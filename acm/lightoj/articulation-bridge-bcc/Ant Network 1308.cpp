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

int t, n, m, cs;
vector<int> adj[mx];
bool saw[mx];
bool is_ap[mx]; // articulation points
int  low[mx], dis[mx];
int tick, cuts, cnt, ncome;
int vis[mx];

void dfs(int v, int parent){
	saw[v] = true;
	low[v] = dis[v] = ++tick;
	int childs = 0;
	for (int i = 0; i < adj[v].size(); ++i){
		int u = adj[v][i];
		if (!saw[u]){
			dfs(u, v);
			low[v] = min(low[v], low[u]);
			if (v != parent && low[u] >= dis[v])
				is_ap[v] = true;
			++childs;
		}
		else if (u != parent)
			low[v] = min(low[v], dis[u]);
	}
	if (v == parent && childs >= 2)
		is_ap[v] = true;
}

void dfs2(int v){
	vis[v] = 1;
	++cnt;
	for(int i = 0; i < adj[v].size(); ++i){
		int u = adj[v][i];
		if (vis[u] != 1 && !is_ap[u])
			dfs2(u);
		if (is_ap[u] && vis[u] != ncome + 1)
			++cuts,
			vis[u] = ncome + 1;
	}
}

int main() {
	cin >> t;
	for (cs = 1; cs <= t; ++cs){
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			adj[i].clear(),
			saw[i] = false,
			is_ap[i] = false,
			vis[i] = 0;
		int a, b;
		for (int i = 0; i < m; ++i)
			cin >> a >> b,
			adj[a].push_back(b),
			adj[b].push_back(a);

		tick = 0;
		for (int i = 0; i < n; ++i)
			if (!saw[i])
				dfs(i, i);
		for (int i = 0; i < n; ++i)
			saw[i] = false;

		ncome = 0;
		unsigned long long mod64 = 1;
		int ans = 0;
		for (int i = 0; i < n; ++i){
			if (vis[i] == 1 || is_ap[i]) continue;
			cuts = 0; cnt = 0;
			dfs2(i);
			++ncome;
			if (cuts < 2){
				++ans;
				mod64 *= cnt;
			}
		}
		
		if (ans == 1)
			mod64 = (n*(n - 1)) / 2,
			++ans;
		cout << "Case " << cs << ": " << ans << " " << mod64 << endl;
	}
	return 0;
}

#endif