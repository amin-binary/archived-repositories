#ifdef do_not_compile_this_file
#include<algorithm>
#include<iterator>
#include<iostream>
#include<cstring>
#include<climits>
#include<cstdio>
#include<string>
#include<vector>
#include<deque>
#include<set>
#include<map>
using namespace std;
#define all(v) begin(v),end(v)
#define rep(i,f,t) for(int i = (f),end_##i = (t); i < end_##i; ++i)


typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
int n, m;
char a[25][25];
int dp[1 << 16][16];
#define x first
#define y second
int N;
ii ps[16];
int t, T;
#define dis(a,b) max(abs(ps[a].x-ps[b].x),abs(ps[a].y-ps[b].y))

int main() {
	ios_base::sync_with_stdio(false);
	cin >> T;
	for (t = 1; T--; ++t){
		cin >> m >> n;
		rep(i, 0, m) cin >> a[i];
		N = 1;
		rep(i, 0, m) rep(j, 0, n)
		if (a[i][j] == 'x')
			ps[0].x = i,
			ps[0].y = j;
		else if (a[i][j] == 'g')
			ps[N].x = i,
			ps[N].y = j,
			++N;
		memset(dp, 0x7f, sizeof(dp));
		dp[1][0] = 0;
		rep(i, 1, (1 << N)) rep(g, 0, N){
			if (dp[i][g] != 0x7f7f7f7f) rep(j, 0, N) if (!(i & (1 << j)))
				dp[i | (1 << j)][j] = min(dp[i | (1 << j)][j], dp[i][g] + dis(g, j));
		}
		int ans = INT_MAX;
		rep(i, 0, N) ans = min(ans, dp[(1 << N) - 1][i] + dis(i, 0));
		cout << "Case " << t << ": " << ans << endl;
	}
	return 0;
}
#endif