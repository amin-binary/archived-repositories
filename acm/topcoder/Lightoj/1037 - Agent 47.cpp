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
#include<bitset>
using namespace std;
#define rep(i,f,t) for(int i = (f),end_##i = (t); i < end_##i; ++i)


typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
	int t = 0, T; cin >> T;
	while (T--){
		int n; cin >> n;
		vi a(n); rep(i, 0, n) cin >> a[i];
		vector<string> vs(n); rep(i, 0, n) cin >> vs[i];
		vvi dis(n, vi(n));
		rep(i, 0, n) rep(j, 0, n) {
			int dd = (vs[i][j] == '0') ? 1 : vs[i][j] - '0';
			dis[i][j] = a[j] / dd + (a[j] % dd > 0);
		}
		vi dp(1 << n, INT_MAX); dp[0] = 0;
		rep(i, 0, 1 << n)
			rep(j, 0, n)
		if (!(i & (1 << j))){
			int mn = a[j];
			rep(k, 0, n) if (i & (1 << k)) mn = min(mn, dis[k][j]);
			dp[i | (1 << j)] = min(dp[i | (1 << j)], dp[i] + mn);
		}
		cout << "Case " << ++t << ": " << dp[(1 << n) - 1] << endl;
	}
	return 0;
}
#endif