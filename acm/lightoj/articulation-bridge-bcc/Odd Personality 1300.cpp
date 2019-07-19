#ifdef no_compile // Successfully Accepted :)

#include <functional>
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
int bcc[mx];
bool bcc_ok[mx];
int color[mx], low[mx], dis[mx];
int tick = 0, cur_color = 1;
bool vis[mx];

void dfs(int v, int parent){
	vis[v] = true;
	low[v] = dis[v] = ++tick;
	for (int i = 0; i < adj[v].size(); ++i){
		int u = adj[v][i];
		if (!vis[u]){
			dfs(u, v);
			low[v] = min(low[v], low[u]);
			if(dis[u] == low[u])
				edg[v].erase(u),
				edg[u].erase(v);
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
			adj[i].clear(),
			edg[i].clear(),
			bcc[i+1] = 0,
			color[i] = 0,
			low[i] = 0,
			dis[i] = 0,
			bcc_ok[i+1] = false,
			vis[i] = false;
		tick = 0;
		cur_color = 1;

		int a, b;
		for (int i = 0; i < m; ++i)
			cin >> a >> b,
			adj[b].push_back(a),
			adj[a].push_back(b),
			edg[a].insert(b),
			edg[b].insert(a);
		for (int i = 0; i < n; ++i)
			if (!vis[i])
				dfs(i, i);
		for (int i = 0; i < n; ++i)
			vis[i] = false;

		int nacc = 0;
		deque<int> que;
		for (int i = 0; i < n; ++i){
			if (vis[i]) continue;
			vis[i] = true;
			color[i] = 1;
			++nacc;
			que.push_back(i);
			while (!que.empty()){
				int tmp = que.front(); que.pop_front();
				bcc[nacc]++;
				for (set<int>::iterator it = edg[tmp].begin(); it != edg[tmp].end(); ++it)
					if (!vis[*it])
						vis[*it] = true,
						color[*it] = color[tmp] * -1,
						que.push_back(*it),
						edg[*it].erase(tmp);
					else if (color[*it] == color[tmp])
						bcc_ok[nacc] = true;
			}
		}

		int rs = 0;
		for (int i = 1; i <= nacc; ++i)
			if (bcc_ok[i])
				rs += bcc[i];
		cout << "Case " << Case << ": " << rs << endl;
	}
	return 0;
}

#endif