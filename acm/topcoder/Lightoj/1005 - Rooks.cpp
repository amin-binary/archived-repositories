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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;

int main() {
	int T; cin >> T;
	rep(t, 1, T + 1){
		int n, k; cin >> n >> k;
		ull ans = k <= n;
		if (ans)
			rep(i, 0, k)
			ans *= ull(n - i)*(n - i),
			ans /= ull(i + 1);
		cout << "Case " << t << ": " << ans << endl;
	}
	return 0;
}
#endif