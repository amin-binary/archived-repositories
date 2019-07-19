#ifdef no_compile
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
#define rep(i,f,t) for(int i = (f),end_##i = (t); i < end_##i; ++i)
#define _MAX 1000

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;

int dp[17][1 << 17], a[17][17], n;

int rec(int i, int mask){
	if (i >= n) return 0;
	int& ans = dp[i][mask];
	if (ans != -1) return ans;

	rep(j, 0, n)
		if ((mask & (1 << j)) == 0)
		ans = max(ans, rec(i + 1, mask | (1 << j)) + a[i][j]);
	return ans;
}
int main(){
	int T; cin >> T;
	rep(t, 1, T + 1){
		cin >> n;
		rep(i, 0, n) rep(j, 0, n) cin >> a[i][j];
		memset(dp, -1, sizeof(dp));
		cout << "Case " << t << ": " << rec(0, 0) << endl;
	}
}

int main_time() {
	int T; cin >> T;
	rep(t, 1, T + 1){
		int n; cin >> n;
		vector<vi> dp(n, vi(1 << (n + 1))), a(n, vi(n));
		set<int> rw[17];
		rep(i, 0, n) rep(j, 0, n) cin >> a[i][j];
		int mx = -1;
		rep(i, 0, n) dp[0][1 << i] = a[0][i], mx = max(mx, a[0][i]), rw[0].insert(1 << i);
		rep(i, 1, n)  rep(j, 0, n) for (si::iterator it = rw[i - 1].begin(); it != rw[i - 1].end(); ++it){ // rep(u, 0, (1 << (n + 1)))
			int u = *it;
			if ((u & (1 << j)) == 0)
				dp[i][u | (1 << j)] = max(dp[i][u | (1 << j)], dp[i - 1][u] + a[i][j]),
				mx = max(dp[i][u | (1 << j)], mx),
				rw[i].insert(u | (1 << j));
		}
		cout << "Case " << t << ": " << mx << endl;
	}
	return 0;
}
#endif;