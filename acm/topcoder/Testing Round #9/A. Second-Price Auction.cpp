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

struct per {
	int x, y;
};
bool operator<(const per& a, const per& b){
	return a.x < b.x;
}

void __main() {
	int n; cin >> n;
	vector<per> v(n);
	rep(i, 0, n) cin >> v[i].x, v[i].y = i + 1;
	sort(all(v));
	cout << v[n - 1].y << ' ' << v[n - 2].x << endl;
}

//#define ONLINE_JUDGE
int main(){
#ifndef ONLINE_JUDGE
	FILE* fin = NULL;
	fin = fopen("in.txt", "w+");
	fprintf(fin, "2\n5 7\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #1 ...\n\tExpected: ");
	printf("2 5\n");
	printf("\tReceived: ");
	__main();
	printf("\n");
	fin = fopen("in.txt", "w+");
	fprintf(fin, "3\n10 2 8\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #2 ...\n\tExpected: ");
	printf("1 8\n");
	printf("\tReceived: ");
	__main();
	printf("\n");
	fin = fopen("in.txt", "w+");
	fprintf(fin, "6\n3 8 2 9 4 14\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #3 ...\n\tExpected: ");
	printf("6 9\n");
	printf("\tReceived: ");
	__main();
	printf("\n");
#else
	__main();
#endif

	return 0;
}
#endif
