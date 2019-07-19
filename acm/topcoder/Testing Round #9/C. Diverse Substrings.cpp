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
int a[3 * 1000 * 100 + 100];
int vis[30];
int n;

int foo(const string& s){
	int vis = 0;
	int cnt = 0;
	rep(i, 0, n){
		a[i] = s[i] - 'a';
		if (!(vis & (1 << a[i])))
			++cnt,
			vis = vis | (1 << a[i]);
	}
	return cnt;
}


void __main() {
	string s; cin >> s;
	n = s.size();
	int ds = foo(s);
	cout << ds << endl;
	rep(i, 1, ds + 1){
		int pv = 0, cr = 0, cnt = 0;
		int ans = 0;
		while (cr < n){
			int N = 0, M = 0;
			while (cnt <= i && cr < n){
				if (!vis[a[cr]]){
					if (cnt == i) break;
					++cnt;
				}
				++vis[a[cr]];
				++cr;
				if (cnt == i)
					++N;
				//++ans;
			}
			while (pv <= cr && cnt == i){
				--vis[a[pv]];
				if (vis[a[pv]] == 0)
					--cnt;
				++pv;
				if (cnt == i)
					++ans;
					//++M;
			}
			ans += N*(N + 1) / 2 ;
			//if(pv < cr) ans += M*(M + 1) / 2;
		}
		cout << ans << endl;
		memset(vis, 0, sizeof(vis));
	}
}

//#define ONLINE_JUDGE
int main(){
#ifndef ONLINE_JUDGE
	FILE* fin = NULL;
	fin = fopen("in.txt", "w+");
	fprintf(fin, "abca\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #1 ...\n\tExpected: ");
	printf("3\n4\n3\n3\n");
	printf("\tReceived: ");
	__main();
	printf("\n");
	fin = fopen("in.txt", "w+");
	fprintf(fin, "aabacaabbad\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #2 ...\n\tExpected: ");
	printf("4\n14\n19\n28\n5\n");
	printf("\tReceived: ");
	__main();
	printf("\n");
#else
	__main();
#endif

	return 0;
}
#endif
