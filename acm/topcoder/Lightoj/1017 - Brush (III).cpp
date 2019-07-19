#ifdef no_compile
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
using namespace std;
#define rep(i,f,t) for(int i = (f),end_##i = (t); i < end_##i; ++i)
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;

int main() {
	int t, T; cin >> T;
	for (t = 0; T--;){
		int n, w, k; cin >> n >> w >> k;
		vi y(n); rep(i, 0, n) scanf("%*d%d", &y[i]);
		sort(all(y));
		vi a(n);
		rep(i, 0, n){
			int lw = i, hi = i;
			while (lw >= 0 && y[hi] - y[lw] <= w) --lw;
			a[i] = hi - lw;
		}
		vector<vi> dp(n, vi(k + 1));
		rep(i, 0, n) rep(j, 1, k+1)
		if (i >= a[i])
			dp[i][j] = max(dp[i - a[i]][j - 1] + a[i], dp[i - 1][j]);
		else
			dp[i][j] = a[i];
		cout << "Case " << ++t << ": " << dp[n - 1][k] << endl;
	}
	return 0;
}
#endif