#ifdef do_not_compile_this_file
#include<algorithm>
#include<iterator>
#include<iostream>
#include<iomanip>
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
double dp[501][501];
int main() {
	ios_base::sync_with_stdio(false);
	rep(i, 0, 501) dp[i][0] = 1;
	//dp[0][0] = dp[1][0] = dp[2][0] = 1;
	rep(i, 1, 501)rep(j, 1, 501)
	//if ((i + j) & 1)
	{
		if (i - 2 >= 0)
			dp[i][j] = double(i) / (i + j)*dp[i - 2][j];
		dp[i][j] += double(j) / (i + j)*dp[i - 1][j - 1];
	}

	int t = 0, T; cin >> T;
	int R, B;
	while (T--){
		cin >> R >> B;
		cout << setprecision(9) << "Case " << ++t << ": " << dp[B][R] << endl;
	}
	return 0;
}
#endif