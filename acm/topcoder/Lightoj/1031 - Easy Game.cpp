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
int a[101], s[101];
#define val(i,j) (s[j] - s[i-1])
int dp[101][101][2];
const int infneg = -1000 * 1000 * 1000;

int dfs(int x, int y, bool turn) {
	if (y < x) return 0;
	int & ret = dp[x][y][turn];
	if (ret != infneg) return ret;
	rep(i, x, y + 1) ret = max(ret, val(x, i) - dfs(i + 1, y, !turn));
	for (int j = y; j >= x; --j) ret = max(ret, val(j, y) - dfs(x, j - 1, !turn));
	return ret;
}

int main() {
	int t, T; cin >> T;
	for (t = 1; t <= T; ++t){
		int n; cin >> n;
		memset(a, 0, sizeof(a));
		memset(s, 0, sizeof(s));
		rep(i, 1, n + 1)
			cin >> a[i],
			s[i] = s[i - 1] + a[i];
		rep(i, 1, n + 1) rep(j, 1, n + 1) dp[i][j][0] = dp[i][j][1] = infneg;
		cout << "Case " << t << ": " << dfs(1, n, true) << endl;
	}
	return 0;
}
#endif