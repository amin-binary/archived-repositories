#ifdef do_not_compile_this_file
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<cstring>
#include<climits>
using namespace std;
#define rep(i,f,t) for(int i = (f),end_##i = (t); i < end_##i; ++i)


typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
	vector<ll> f(33), g(33); f[2] = g[2] = 1;
	rep(i, 3, 33) f[i] = g[i - 1] + (1ll << (i - 2)), g[i] = g[i - 1] + f[i];

	int t = 0, T; cin >> T;
	while (T--) {
		ll n; cin >> n;
		ll ans = 0;
		for (int i = 32; i > 0; --i) {
			if (n & (1ll << i)){
				ans += g[i];
				if (n &(1ll << (i - 1))){
					//cerr << "--> " << (n & ((1ll << (i - 1)) - 1)) + 1 << endl;
					ans += (n & ((1ll << (i - 1)) - 1)) + 1;
				}
			}
		}
		cout << "Case " << ++t << ": " << ans << endl;
	}
	return 0;
}
#endif