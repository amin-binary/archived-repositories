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
#include <queue>
#include <cmath>
#include <list>
#include <set>
#include <map>
#define rep(i,m,n) for(int i=(m),_end=(n);i < _end;++i)
#define repe(i,m,n) for(int i=(m), _end =(n);i <= _end;++i)
typedef long long ll;
using namespace std;

const int mx = 500 + 10;
const int inf = 20000 + 10;

priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;

int T, n, m, source;
bool saw[mx];
int dist[mx];
vector<pair<int, int> > adj[mx];

int main() {
	cin >> T;
	repe(t, 1, T){
		cin >> n >> m;
		rep(i, 0, n)
			adj[i].clear(),
			saw[i] = false,
			dist[i] = inf;
		int a, b, w;
		rep(i, 0, m)
			cin >> a >> b >> w,
			adj[a].push_back(make_pair(w, b)),
			adj[b].push_back(make_pair(w, a));

		
		cin >> source;
		pq.push(make_pair(0, source));
		dist[source] = 0;
		pair<int, int> tmp, tmp2;
		while (!pq.empty()){
			tmp = pq.top(); pq.pop();
			int v = tmp.second, w = dist[tmp.second];
			if (saw[v]) continue;
			saw[v] = true;

			rep(j, 0, adj[v].size())
			{
				tmp2 = adj[v][j];
				int u = tmp2.second, w2 = tmp2.first;
				if (max(w, w2) < dist[u])
					dist[u] = max(w, w2),
					pq.push(make_pair(dist[u],u));

			}
		}
		printf("Case %d:\n", t);
		rep(i, 0, n)
			if (dist[i] != inf)
				cout << dist[i] << endl;
			else
				cout << "Impossible\n";
	}
	return 0;
}

#endif