#ifdef no_compile
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
using namespace std;
#define rep(i,f,t) for(int i = (f),end_##i = (t); i < end_##i; ++i)
#define _MAX 1000

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;

int main() {
	int T; cin >> T;
	for (int t = 1; T--; ++t){
		string a, b; cin >> a >> b;
		int as = a.size(), bs = b.size();
		vector<vector<ll> > cnt(as + 1, vector<ll>(bs + 1)), len(as + 1, vector<ll>(bs + 1));
		rep(i, 0, as + 1) cnt[i][0] = 1, len[i][0] = i;
		rep(j, 0, bs + 1) cnt[0][j] = 1, len[0][j] = j;
		rep(i, 1, as + 1) rep(j, 1, bs + 1)
		if (a[i - 1] == b[j - 1])
			len[i][j] = len[i - 1][j - 1] + 1,
			cnt[i][j] = cnt[i - 1][j - 1];
		else if (len[i - 1][j] == len[i][j - 1])
			len[i][j] = len[i - 1][j] + 1,
			cnt[i][j] = cnt[i - 1][j] + cnt[i][j - 1];
		else if (len[i - 1][j] < len[i][j - 1])
			len[i][j] = len[i - 1][j] + 1,
			cnt[i][j] = cnt[i - 1][j];
		else if (len[i - 1][j] > len[i][j - 1])
			len[i][j] = len[i][j - 1] + 1,
			cnt[i][j] = cnt[i][j - 1];
		cout << "Case " << t << ": " << len[as][bs] << ' ' << cnt[as][bs] << endl;
	}
	return 0;
}
#endif