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
#define  X first
#define  Y second
const int mx = 510;
ii a[mx][mx], v[mx][mx];
int dp[mx][mx], x[mx][mx], y[mx][mx];

int main() {
	ios_base::sync_with_stdio(false);
	int t = 0, T; cin >> T;
	while (T--){
		int n, m; cin >> m >> n;
		rep(i, 1, m + 1) rep(j, 1, n + 1) cin >> a[i][j].X, x[i][j] = x[i][j - 1] + a[i][j].X;
		rep(i, 1, m + 1) rep(j, 1, n + 1) cin >> a[i][j].Y, y[i][j] = y[i - 1][j] + a[i][j].Y;
		rep(i, 1, m + 1) rep(j, 1, n + 1) dp[i][j] = max(dp[i - 1][j] + x[i][j], dp[i][j - 1] + y[i][j]);
		cout << "Case " << ++t << ": " << dp[m][n] << endl;
	}
	return 0;
}
#endif