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
//#define max(a,b,c) max(a,max(a,b))


typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
	int t = 0, T; cin >> T;
	while (T--){
		string s; cin >> s; int n = s.size();
		vvi dp(n + 1, vi(n + 1));
		rep(i, 1, n + 1) dp[i][i] = 1;
		rep(k, 1, n) for (int i = 1; i + k <= n; ++i){
			int j = i + k;
			dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
			if (s[i - 1] == s[j - 1])
				dp[i][j] = max(dp[i][j], 2 + dp[i + 1][j - 1]);
		}
		printf("Case %d: %d\n", ++t, n - dp[1][n]);
	}
	return 0;
}
#endif