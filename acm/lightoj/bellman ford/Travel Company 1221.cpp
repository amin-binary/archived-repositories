#ifdef no_compile // Successfully Accepted :)

#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <list>
#include <set>
#include <map>
#define rep(i,m,n) for(int i=(m),_end=(n);i < _end;++i)
#define repe(i,m,n) for(int i=(m), _end =(n);i <= _end;++i)
typedef long long ll;
using namespace std;

const int mx = 100 + 10;

int T, N, R, P;
int d[mx];
vector< pair<int, int> > edg;
vector<int> wt;


int main() {
	cin >> T;
	repe(t, 1, T){
		cin >> N >> R >> P;
		rep(i, 0, N) d[i] = 0;
		edg.clear();
		wt.clear();

		int a, b, income, expense;
		rep(i, 0, R)
			cin >> a >> b >> income >> expense,
			edg.push_back(make_pair(a, b)),
			wt.push_back(expense*P - income);

		rep(i,0,N)
			rep(j, 0, R){
				int v = edg[j].first, u = edg[j].second, w = wt[j];
				if (d[v] + w < d[u]) d[u] = d[v] + w;
		}

		bool have_negative_cycle = false;
		rep(j, 0, R){
			int v = edg[j].first, u = edg[j].second, w = wt[j];
			if (d[v] + w < d[u]) have_negative_cycle = true;
		}
		
		printf("Case %d: %s\n", t, (have_negative_cycle ? "YES" : "NO"));
	}
	return 0;
}

#endif