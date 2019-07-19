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
#include <queue>
#include <deque>
#include <cmath>
#include <list>
#include <set>
#include <map>
#define rep(i,m,n) for(int i=(m),_end=(n);i < _end;++i)
#define repe(i,m,n) for(int i=(m), _end =(n);i <= _end;++i)
typedef long long ll;
using namespace std;
typedef pair<int, int> pii;

const int mx = 100 + 10;
const int inf = INT_MAX;

int T, n, m;
vector<pii> adj[mx];
int dist[mx];
priority_queue<pii, vector<pii>, greater<pii> > pq;


int main() {
	cin >> T;
	repe(t, 1, T){
		cin >> n >> m;
		repe(i, 1, n)
			dist[i] = inf,
			adj[i].clear();
		int v,u, w;
		rep(i, 0, m)
			cin >> v >> u >> w,
			adj[v].push_back(make_pair(w, u)),
			adj[u].push_back(make_pair(w, v));

		dist[1] = 0;
		pq.push(make_pair(0, 1));
		pii tmp;
		while (!pq.empty()){
			tmp = pq.top(); pq.pop();
			v = tmp.second; w = tmp.first;
			if (w > dist[v]) continue;
			rep(j, 0, adj[v].size())
			{
				u = adj[v][j].second;
				int w2 = adj[v][j].first;

				if (w + w2 < dist[u])
					dist[u] = w + w2,
					pq.push(make_pair(w + w2, u));
			}
		}

		if (dist[n] != inf)
			printf("Case %d: %d\n", t, dist[n]);
		else
			printf("Case %d: Impossible\n", t);
	}
	return 0;
}

#endif