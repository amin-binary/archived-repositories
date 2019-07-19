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

const int mx = 1000 + 10;

int T, n, m;
vector<int> adj[mx];
vector< pair<int, int> > edg;
vector<int> wt;
int d[mx];
bool saw[mx];

int main() {
	cin >> T;
	repe(t, 1, T){
		cin >> n >> m;
		rep(i, 0, n) d[i] = 0, saw[i] = false, adj[i].clear();
		edg.clear(); wt.clear();
		int a, b, c;
		rep(i, 0, m) cin >> a >> b >> c, wt.push_back(c), edg.push_back(make_pair(b, a)), adj[b].push_back(a);

		deque<int> que;
		rep(i, 0, n)
			rep(j, 0, m)
		{
			int v = edg[j].first, u = edg[j].second;
			if (d[v] + wt[j] < d[u])
				d[u] = d[v] + wt[j];
		}
		rep(j, 0, m){
			int v = edg[j].first, u = edg[j].second;
			if (d[v] + wt[j] < d[u])
				saw[v] = true,
				que.push_back(v);
		}
		int tmp;
		cout << "Case " << t << ":";
		if (que.empty()) 
			cout << " impossible\n";
		else {
			while (!que.empty()){
				tmp = que.front(); que.pop_front();
				rep(i, 0, adj[tmp].size())
					if (!saw[adj[tmp][i]])
						saw[adj[tmp][i]] = true,
						que.push_back(adj[tmp][i]);
			}
			rep(i, 0, n)
				if (saw[i])
					cout << ' ' << i;
			cout << endl;
		}
	}
	return 0;
}

#endif