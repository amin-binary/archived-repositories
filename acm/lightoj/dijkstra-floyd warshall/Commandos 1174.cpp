#ifdef no_compile  // Successfully Accepted :)

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

int T, n, R;
vector<int> adj[mx];
int dis_source[mx], dis_des[mx];
int source, des;

priority_queue<pii, vector<pii>, greater<pii> > pq;

int main() {
	cin >> T;
	repe(t, 1, T){
		cin >> n >> R;
		rep(i, 0, n)
			adj[i].clear(),
			dis_source[i] = inf,
			dis_des[i] = inf;
		int a, b;
		rep(i, 0, R)
			cin >> a >> b,
			adj[a].push_back(b),
			adj[b].push_back(a);
		cin >> source >> des;

		dis_source[source] = 0;
		pq.push(make_pair(0, source));
		
		while (!pq.empty()){
			int v = pq.top().second, w = pq.top().first; pq.pop();
			if (w > dis_source[v])
				continue;
			rep(j, 0, adj[v].size())
				if (dis_source[v] + 1 < dis_source[adj[v][j]])
					dis_source[adj[v][j]] = dis_source[v] + 1,
					pq.push(make_pair(dis_source[v] + 1, adj[v][j]));
		}

		dis_des[des] = 0;
		pq.push(make_pair(0, des));

		while (!pq.empty()){
			int v = pq.top().second, w = pq.top().first; pq.pop();
			if (w > dis_des[v])
				continue;
			rep(j, 0, adj[v].size())
				if (dis_des[v] + 1 < dis_des[adj[v][j]])
					dis_des[adj[v][j]] = dis_des[v] + 1,
					pq.push(make_pair(dis_des[v] + 1, adj[v][j]));
		}

		int rs = 0;
		rep(i, 0, n)
			if (dis_source[i] + dis_des[i] > rs)
				rs = dis_source[i] + dis_des[i];
		printf("Case %d: %d\n", t, rs);
	}
	return 0;
}

#endif