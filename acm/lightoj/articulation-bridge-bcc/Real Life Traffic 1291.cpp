#ifdef no_compile // problem successfully accepted :)

#include  <functional>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cfloat>
#include <stack>
#include <deque>
#include <queue>
#include <cmath>
#include <list>
#include <set>
#include <map>
#define X first
#define Y second
#define rep(i,m,n) for(int i=(m);i<(int)(n);++i)
#define contain(con,val) (find(con.begin(),con.end(),(val)) != con.end())
#define foreach(it,c,type) for(type::iterator it=c.begin(),End=c.end();it!=End;++it)
#define rforeach(rit,c,type) for(type::reverse_iterator rit=c.rbegin(),rEnd=c.rend();rit!=rEnd;++it)
using namespace std;
typedef pair<int, int> prii; typedef pair<string, int> prsi;

const int mx = 10 * 1000 + 10;
int t, n, m, Case;
vector<int> adj[mx];
set<int> edg[mx];
vector< pair<int, int> > bridge;
int acc[mx], cnt[mx];
bool vis[mx];
int dis[mx], low[mx];
int tick = 0;

void dfs(int v, int parent){
	++tick;
	vis[v] = true;
	dis[v] = low[v] = tick;

	for (int i = 0; i < adj[v].size(); ++i){
		int u = adj[v][i];
		if (!vis[u]){
			dfs(u,v);
			low[v] = min(low[v], low[u]);

			if (low[v] < low[u]){
				edg[v].erase(u);
				edg[u].erase(v);
				bridge.push_back(make_pair(min(u, v), max(u, v)));
			}
		}
		else if (u != parent)
			low[v] = min(low[v], dis[u]);
	}
}

int main() {
	cin >> t;
	for (Case = 1; Case <= t; ++Case){
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			edg[i].clear(),
			adj[i].clear(),
			acc[i] = 0,
			cnt[i+1] = 0,
			vis[i] = false,
			dis[mx] = 0,
			low[mx] = 0;

		int a, b;
		for (int i = 0; i < m; ++i)
			cin >> a >> b,
			adj[a].push_back(b),
			adj[b].push_back(a),
			edg[a].insert(b),
			edg[b].insert(a);

		tick = 0;
		bridge.clear();
		for (int i = 0; i < n; ++i)
			if (!vis[i])
				dfs(i, i);

		int nacc = 0;
		deque<int> que;
		for (int i = 0; i < n; ++i)vis[i] = false;
		for (int i = 0; i < n; ++i) {
			if (vis[i]) continue;
			++nacc;
			vis[i] = true;
			que.push_back(i);
			while (!que.empty()){
				int cur = que.front(); que.pop_front();
				acc[cur] = nacc;
				for (set<int>::iterator it = edg[cur].begin(); it != edg[cur].end(); ++it)
					if (!vis[*it])
						vis[*it] = true,
						que.push_back(*it);
			}
		}
		
		for (int i = 0; i < bridge.size(); ++i)
			cnt[acc[bridge[i].first]]++,
			cnt[acc[bridge[i].second]]++;

		int ACC = 0;
		for (int i = 1; i <= nacc; ++i)
			if (cnt[i] == 1)
				++ACC;
		cout << "Case " << Case << ": " << (ACC + 1) / 2 << endl;
	}
	return 0;
}

#endif