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

int dp[1000 * 1000 + 1];
bool ok[1000 * 1000 + 1];
int tmp;

void __main() {
	memset(dp, 0, sizeof(dp));
	int n, m; cin >> n >> m;
	rep(i, 0, n){
		cin >> tmp;
		++dp[tmp];
	}
	int st = 0;
	int ans = 0;
	rep(j, 0, m){
		cin >> tmp;
		while (st != tmp && st < 1000 * 1000 + 1)
			dp[st + 1] += dp[st],
			++st;
		if (dp[tmp])
			++ans,
			--dp[tmp];
	}
	cout << n - ans << endl;
}

//#define ONLINE_JUDGE
int main(){
#ifndef ONLINE_JUDGE
	FILE* fin = NULL;
	fin = fopen("in.txt", "w+");
	fprintf(fin, "3 5\n1 2 3\n1 2 2 3 3\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #1 ...\n\tExpected: ");
	printf("0\n");
	printf("\tReceived: ");
	__main();
	printf("\n");
	fin = fopen("in.txt", "w+");
	fprintf(fin, "3 5\n1 2 3\n1 1 1 1 1\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #2 ...\n\tExpected: ");
	printf("2\n");
	printf("\tReceived: ");
	__main();
	printf("\n");
	fin = fopen("in.txt", "w+");
	fprintf(fin, "3 1\n2 3 4\n1\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #3 ...\n\tExpected: ");
	printf("3\n");
	printf("\tReceived: ");
	__main();
	printf("\n");
#else
	__main();
#endif

	return 0;
}
#endif
