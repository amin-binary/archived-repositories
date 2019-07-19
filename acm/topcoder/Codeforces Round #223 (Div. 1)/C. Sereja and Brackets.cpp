#ifdef do_not_compile_this_file
#include<iostream>
#include<algorithm>
#include<climits>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<deque>
#include<set>
#include<map>
using namespace std;
#define rep(i,f,t) for(int i = (f),end_##i = (t); i < end_##i; ++i)
#define all(v) begin(v),end(v)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
const int Mx = 1000 * 1000 + 10;
int dp[Mx][21], op[Mx][21], cl[Mx][21];
char a[Mx];

void __main() {
	scanf("%s", a);
	int n = strlen(a);
	rep(i, 0, n)
		op[i][0] = (a[i] == '('),
		cl[i][0] = (a[i] == ')');

	for (int j = 1; (1 << j) <= n; ++j)  for (int i = 0; i + (1 << j) <= n; ++i){
		int k = i + (1 << (j - 1));
		int dif = min(op[i][j - 1], cl[k][j - 1]);
		dp[i][j] = dp[i][j - 1] + dp[k][j - 1] + 2 * dif;
		op[i][j] = op[i][j - 1] + op[k][j - 1] - dif;
		cl[i][j] = cl[i][j - 1] + cl[k][j - 1] - dif;
	}
	int m; scanf("%d", &m);
	rep(i, 0, m){
		int x, y; scanf("%d %d", &x, &y); --x;
		int j = 20, tdp = 0, top = 0;
		while (x < y && j >= 0){
			if (y - x >= (1 << j)){
				int dif = min(top, cl[x][j]);
				top += op[x][j] - dif;
				tdp += dp[x][j] + 2 * dif;
				x += (1 << j);
			}
			--j;
		}
		printf("%d\n", tdp);
	}
}

//#define ONLINE_JUDGE
int main(){
#ifndef ONLINE_JUDGE
	FILE* fin = NULL;
	fin = fopen("in.txt", "w+");
	fprintf(fin, "())(())(())(\n7\n1 1\n2 3\n1 2\n1 12\n8 12\n5 11\n2 10\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #1 ...\n\tExpected: ");
	printf("0\n0\n2\n10\n4\n6\n6\n");
	printf("\tReceived: ");
	__main();
	printf("\n");
#else
	__main();
#endif

	return 0;
}
#endif
