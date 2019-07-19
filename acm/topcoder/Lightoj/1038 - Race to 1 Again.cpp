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
const int mxx = 100 * 1000 + 1;
double dp[mxx];

int main() {
	int cnt; double sum;
	rep(i, 2, mxx){
		sum = cnt = 0;
		for (int j = 1; j *j <= i; ++j)
			if (i%j == 0){
				sum += dp[j];
				++cnt;
				if (j*j != i) sum += dp[i / j], ++cnt;
			}
		dp[i] = (sum + cnt) / (cnt - 1);
	}
	int t = 0, n, T; scanf("%d", &T);
	while (T--){
		scanf("%d", &n);
		printf("Case %d: %.9f\n", ++t, dp[n]);
	}
	return 0;
}
#endif