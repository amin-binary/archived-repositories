#ifdef no_compile // Successfully Accepted :)

#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <string>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <list>
#include <set>
#include <map>
#define rep(i,m,n) for(int i=(m),_end=(n);i < _end;++i)
#define repe(i,m,n) for(int i=(m), _end =(n);i <= _end;++i)
#define ff first
#define ss second
typedef long long ll;
using namespace std;

typedef pair<int, int> point;
struct edge { point v, u; double d; };

const int mx = 100 + 10;
const double BIG = 1e12;
const double EPS = 1e-9;

int T, n;
edge edg[mx];
map<point, vector<int> > mp;
double mat[mx][mx];

inline bool is_left(point& a, point& b, point& c){
	return (b.ff - a.ff) * (c.ss - a.ss) - (b.ss - a.ss) * (c.ff - a.ff) >= 0;
}

inline double dis(point& a, point& b){
	return sqrt((a.ff - b.ff)*(a.ff - b.ff) + (a.ss - b.ss)*(a.ss - b.ss));
}

int main() {
	cin >> T;
	repe(t, 1, T){
		point bull;
		cin >> n >> bull.ff >> bull.ss;
		mp.clear();
		rep(i, 0, n){
			cin >> edg[i].v.ff >> edg[i].v.ss >> edg[i].u.ff >> edg[i].u.ss;
			if (!is_left(edg[i].v, edg[i].u, bull))
				swap(edg[i].v, edg[i].u);
			edg[i].d = dis(edg[i].v, edg[i].u);
			mp[edg[i].v].push_back(i);
		}
		rep(i, 0, n)
			rep(j, 0, n)
			mat[i][j] = BIG;

		edge a, b;
		rep(i, 0, n){
			a = edg[i];
			vector<int>& adj = mp[a.u];
			rep(j, 0, adj.size()){
				b = edg[adj[j]];
				if (is_left(a.v, a.u, b.u))
					mat[i][adj[j]] = a.d + b.d;
			}
		}
		rep(k, 0, n)
			rep(i, 0, n)
			rep(j, 0, n)
			mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
		double rs = BIG;
		rep(i, 0, n)
			rs = min(mat[i][i], rs);
		if (BIG - rs < EPS)
			rs = -1.000000;
		printf("Case %d: %.8lf\n", t, rs);
	}
	return 0;
}


#endif