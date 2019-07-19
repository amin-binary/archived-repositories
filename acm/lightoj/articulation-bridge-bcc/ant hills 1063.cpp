#ifdef no_compile // problem successfully accepted :)

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

int t, n, m;
vector<int> adj[10 * 1000 + 10];
int child[10 * 1000 + 10];
int low[10 * 1000 + 10];
int dis[10 * 1000 + 10];
int cur_vertexes;
int g_time;

void dfs(int v,int parent){
	dis[v] = low[v] = ++g_time;
	bool fine = false;
	for (int i = 0, _end = adj[v].size(); i < _end; ++i)
	{
		int u = adj[v][i];
		if (dis[u] == -1){
			dfs(u, v);
			low[v] = min(low[v], low[u]);
			++child[v];
			if (parent != v && low[u] >= dis[v])
				fine = true;
		}
		else if (u != parent)
			low[v] = min(low[v], dis[u]);
	}
	if (parent == v && child[v] >= 2)
		fine = true;
	if (fine)
		++cur_vertexes;
		//cout << "----> " << v << endl;
}

int main() {
	cin >> t;
	for (int Case = 1; Case <= t; ++Case){
		cin >> n >> m;
		int a, b;
		for (int i = 1; i <= n; ++i)
			adj[i].clear(),
			child[i] = 0,
			dis[i] = -1;

		for (int i = 0; i < m; ++i)
			cin >> a >> b,
			adj[a].push_back(b),
			adj[b].push_back(a);
		g_time = 0;
		cur_vertexes = 0;
		for (int i = 1; i <= n; ++i)
			if (dis[i] == -1)
				dfs(i, i);
		cout << "Case " << Case << ": " << cur_vertexes << endl;
	}
	return 0;
}

#endif