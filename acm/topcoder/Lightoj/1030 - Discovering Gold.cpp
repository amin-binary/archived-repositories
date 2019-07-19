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

int main() {
	int t, T; cin >> T;
	for (t = 1; t <= T; ++t){
		int n; cin >> n;
		int b[101];
		double a[101] = {};
		a[1] = 1;
		rep(i, 1, n + 1){
			cin >> b[i];
			int tmp = min(n - i, 6);
			rep(j, i + 1, min(n, i + 6)+1)
				a[j] += a[i] / tmp;
		}
		a[n] = 1;
		double sm = 0;
		rep(i, 1, n+1) sm += a[i] * b[i];
		printf("Case %d: %.8f\n", t, sm);
	}
	return 0;
}
#endif