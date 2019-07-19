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
ll dp[1 << 16][20];
bool vis[1 << 16];
int pw[17];
int base, k, len;
void dfs(int mask){
	if (mask == 0 || vis[mask]) return;
	vis[mask] = true;
	rep(j, 0, k) dp[mask][j] = 0;
	rep(i, 0, base){
		if (mask & (1 << i)){
			--len;
			dfs(mask & ~(1 << i));
			++len;
			rep(j, 0, k)
				dp[mask][(j + i*pw[len - 1]) % k] += dp[mask & ~(1 << i)][j];
		}
	}
}
int mp[256];
int main() {
	rep(i, 0, 10) mp[i + '0'] = 1 << i;
	for (int c = 'A'; c <= 'F'; ++c) mp[c] = 1 << (c - 'A' + 10);
	int T; cin >> T;
	rep(t, 1, T + 1){
		cin >> base >> k;
		string s; cin >> s;
		int mask = 0;
		rep(i, 0, s.size()) mask = mask | mp[s[i]];
		memset(vis, false, sizeof(vis));
		pw[0] = 1;
		rep(i, 1, 17) pw[i] = (pw[i - 1] * base) % k;
		dp[0][0] = 1;
		len = s.size();
		dfs(mask);
		cout << "Case " << t << ": " << dp[mask][0] << endl;
	}
	return 0;
}
#endif