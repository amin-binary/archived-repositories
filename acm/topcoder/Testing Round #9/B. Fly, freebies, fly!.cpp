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


void __main() {
	int n; cin >> n;
	vi v(n); rep(i, 0, n) cin >> v[i];
	sort(all(v));
	int mx = 0, t; cin >> t;
	rep(i, 0, n) mx = max(mx, int(upper_bound(all(v), v[i] + t) - v.begin())-i);
	cout << mx << endl;
}

//#define ONLINE_JUDGE
int main(){
#ifndef ONLINE_JUDGE
	FILE* fin = NULL;
	fin = fopen("in.txt", "w+");
	fprintf(fin, "6\n4 1 7 8 3 8\n1\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #1 ...\n\tExpected: ");
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
