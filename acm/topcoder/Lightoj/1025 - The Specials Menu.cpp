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
ll dp[65][65];
string s;
ll dfs(int x, int y){
	if (x > y) return 0;
	if (dp[x][y] != -1) return dp[x][y];
	if (x == y) return dp[x][y] = 1;
	dp[x][y] = /*2 +*/ (1 + (s[x] == s[y]))*dfs(x + 1, y - 1) + (s[x] == s[y]);
	dp[x][y] += dfs(x + 1, y) - dfs(x + 1, y - 1);
	dp[x][y] += dfs(x, y - 1) - dfs(x + 1, y - 1);
	return dp[x][y];
}

int main() {
	int t, T; cin >> T;
	rep(t, 1, T + 1){
		cin >> s;
		memset(dp, -1, sizeof(dp));
		int n = s.size();
		cout << "Case " << t << ": " << dfs(0, n - 1) << endl;
	}
	return 0;
}
#endif