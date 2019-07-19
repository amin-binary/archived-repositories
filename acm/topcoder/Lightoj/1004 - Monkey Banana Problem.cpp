#ifdef no_compile
#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
using namespace std;
#define rep(i,f,t) for(int i = (f),end_##i = (t); i < end_##i; ++i)
#define _MAX 1000

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;

int main() {
	ios_base::sync_with_stdio(false);
	int T; cin >> T;
	rep(t, 0, T){
		int n; cin >> n;
		vector<ll> c(n + 1), p(n + 1);
		rep(i, 0, n){
			rep(j, 0, i + 1)
				cin >> c[j],
				c[j] += max(p[j], j > 0 ? p[j - 1] : 0);
			c.swap(p);
		}
		for (int i = n - 1; i >= 1; --i){
			rep(j, 0, i)
				cin >> c[j],
				c[j] += max(p[j], p[j + 1]);
			c.swap(p);
		}
		cout << "Case " << t + 1 << ": " << p[0] << endl;
	}
	return 0;
}
#endif