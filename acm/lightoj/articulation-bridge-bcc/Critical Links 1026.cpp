#ifdef no_compile // problem accepted sucessfully :)

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

int t, n;
vector<int> adj[10 * 1000 + 10];
vector<pair<int, int> > bridge;
int dis[10 * 1000 + 10], low[10 * 1000 + 10];
int g_time;

void dfs(int v, int parent){
	dis[v] = low[v] = ++g_time;
	for (int i = 0, _end = adj[v].size(); i < _end; ++i){
		int u = adj[v][i];
		if (dis[u] == -1){
			dfs(u, v);
			low[v] = min(low[v], low[u]);
			if (dis[u] == low[u])
				bridge.push_back(make_pair(min(u, v), max(u, v)));
		}
		else if (u != parent)
			low[v] = min(low[v], dis[u]);
	}
}

int main() {
	cin >> t;
	for (int Case = 1; Case <= t; ++Case){
		cin >> n;
		int u, k, v;
		rep(i, 0, n){
			scanf("%d (%d)", &u, &k);
			adj[i].clear();
			dis[i] = -1;

			rep(j, 0, k)
				cin >> v,
				adj[u].push_back(v);
		}
	
	g_time = 0;
	bridge.clear();
	rep(i, 0, n)
		if (dis[i] == -1)
			dfs(i, i);
	sort(bridge.begin(), bridge.end());
	cout << "Case " << Case << ":\n";
	cout << bridge.size() << " critical links\n";
	for (int i = 0, _end = bridge.size(); i < _end; ++i)
		cout << bridge[i].first << " - " << bridge[i].second << endl;

	}
	return 0;
}

#endif