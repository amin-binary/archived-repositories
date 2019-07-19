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
#include<time.h>
using namespace std;
#define rep(i,f,t) for(int i = (f),end_##i = (t); i < end_##i; ++i)


typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int mx = 1000 + 10;
int dp[mx];
bool ispal[mx][mx];

int main() {
	ios_base::sync_with_stdio(false);
	int t = 0, T; cin >> T;
	while (T--){
		string s; cin >> s;
		int n = s.size();
		memset(dp, 0x7F, sizeof(dp));
		memset(ispal, false, sizeof(ispal));
		rep(i, 0, n) ispal[i][i] = true;
		rep(k, 1, n) for (int i = 0; i + k < n; ++i){
			int j = i + k;
			ispal[i][j] = (s[i] == s[j] && (ispal[i + 1][j - 1] || i + 1 >= j - 1));
		}
		dp[0] = 0;
		rep(i, 1, n+1) rep(j, 1, i + 1){
			if (ispal[j-1][i-1])
				dp[i] = min(dp[i], 1 + dp[j - 1]);
		}
		cout << "Case " << ++t << ": " << dp[n] << endl;
	}
	return 0;
}
#endif