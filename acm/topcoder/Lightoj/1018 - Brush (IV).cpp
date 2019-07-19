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

int x[17], y[17];
int dp[1 << 17];
int n;

inline bool one_line(int a, int b, int c){
	return (x[a] - x[b])*(y[b] - y[c]) == (y[a] - y[b]) * (x[b] - x[c]);
}

int rec(int used){
	if (dp[used] != -1) return dp[used];
	int& ret = dp[used];
	int cnt = 0;
	rep(i, 0, n) cnt += (used & (1 << i)) == 0;
	if (cnt == 1) return ret = cnt;

	ret = INT_MAX;
	int bt, tmp;
	rep(i, 0, n) if ((used & (1 << i)) == 0){
		tmp = used | (1 << i);
		rep(j, i + 1, n) if ((tmp & (1 << j)) == 0){
			tmp = tmp | (1 << j);
			bt = used | (1 << i);
			bt = bt | (1 << j);
			rep(u, j+1, n) if (((tmp & (1 << u)) == 0) && one_line(i, j, u)){
				tmp = tmp | (1 << u);
				bt = bt | (1 << u);
			}
			ret = min(ret, 1 + rec(bt));
		}
		break;
	}
	return ret;
}

int main(){
	int t, T; cin >> T;
	for (t = 0; T--;){
		cin >> n;
		rep(i, 0, n) cin >> x[i] >> y[i];
		memset(dp, -1, sizeof(dp));
		dp[(1 << n) - 1] = 0;
		cout << "Case " << ++t << ": " << rec(0) << endl;
	}
	return 0;
}

int main_time() {
	int t, T; cin >> T;
	int mp[(1 << 16) + 1];
	mp[1] = 0;
	for (int i = 2; i <= (1 << 16); i *= 2)
		mp[i] = 1 + mp[i / 2];
	for (t = 0; T--;){
		int n; cin >> n;
		vi x(n), y(n); rep(i, 0, n) cin >> x[i] >> y[i];
		vi cnt(1 << n), ok(1 << n), _or(1 << n), zm(1 << n); ok[0] = true;
		int ans = INT_MAX, zml = 1;
		rep(i, 1, (1 << n)){
			int u = i & (i - 1);
			if (ok[u]){
				cnt[i] = cnt[u] + 1;
				if (cnt[u] + 1 <= 2)
					ok[i] = true;
				else{
					int v = u & (u - 1);
					int a = mp[i & ~(i - 1)], b = mp[u & ~(u - 1)], c = mp[v & ~(v - 1)];
					if ((x[c] - x[b])*(y[b] - y[a]) == (y[c] - y[b])*(x[b] - x[a]))
						ok[i] = true;
				}
			}
			if (ok[i]) zm[zml++] = i;
			//_or[i] = _or[u] | i;
			//if (ok[i] && _or[i] == ((1 << n) - 1))
			//ans = min(cnt[i], ans);
		}
		_or[0] = zm[0];
		rep(i, 1, 1 << zml){
			_or[i] = _or[i&(i - 1)] | zm[i];
			if (_or[i] == ((1 << n) - 1))
				ans = min(ans, cnt[zm[i&(i - 1)]] + cnt[zm[i]]);
		}
		cout << "Case " << ++t << ": " << ans << endl;
	}
	return 0;
}
#endif