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

const int mx = 5000 + 10;
const int inf = INT_MAX;

int T, n, R;
vector<pii> adj[mx];
int dist[mx], dist2[mx];
priority_queue<pii, vector<pii>, greater<pii> > pq;


int main() {
	cin >> T;
	repe(t, 1, T){
		cin >> n >> R;
		repe(i, 1, n)
			dist[i] = inf,
			dist2[i] = inf,
			adj[i].clear();
		int v, u, w;
		rep(i, 0, R)
			cin >> v >> u >> w,
			adj[v].push_back(make_pair(w, u)),
			adj[u].push_back(make_pair(w, v));

		dist[1] = 0;
		pq.push(make_pair(0, 1));
		pii tmp;
		while (!pq.empty()){
			tmp = pq.top(); pq.pop();
			v = tmp.second; w = tmp.first;
			if (w > dist[v]) {
				if (w < dist2[v])
					dist2[v] = w;
				else
					continue;
			}
			rep(j, 0, adj[v].size())
			{
				u = adj[v][j].second;
				int w2 = adj[v][j].first;

				if (w + w2 < dist[u])
					dist[u] = w + w2,
					pq.push(make_pair(w + w2, u));
				else if (w + w2 < dist2[u])
					pq.push(make_pair(w + w2, u));
			}
		}
		
		printf("Case %d: %d\n", t, dist2[n]);
	}
	return 0;
}

#endif