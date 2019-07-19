#ifdef do_not_compile_this_file
#include<algorithm>
#include<iterator>
#include<iostream>
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

int main() {
	ios_base::sync_with_stdio(false);
	int T; cin >> T;
	rep(t, 1, T + 1){
		int a = 0, b = 0, c = 0, x, y, z, A, B, C, n;
		cin >> n;
		rep(i, 0, n){
			cin >> x >> y >> z;
			A = x + min(b, c);
			B = y + min(a, c);
			C = z + min(a, b);
			a = A;
			b = B;
			c = C;
		}
		cout << "Case " << t << ": " << min(a, min(b, c)) << endl;
	}
	return 0;
}
#endif