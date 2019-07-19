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
#include <cmath>
#include <list>
#include <set>
#include <map>
#define rep(i,m,n) for(int i=(m),_end=(n);i < _end;++i)
#define repe(i,m,n) for(int i=(m), _end =(n);i <= _end;++i)
typedef long long ll;
using namespace std;

const int mx = 20 * 1000 + 10;

int T, n, m;
vector<int> adj[mx], backadj[mx];
vector<int> order;
int scc[mx], indeg[mx], outdeg[mx];
bool vis[mx];
int nscc, result;

void dfs(int v){
	vis[v] = true;
	rep(i, 0, adj[v].size())
		if (!vis[adj[v][i]])
			dfs(adj[v][i]);
	order.push_back(v);
}

void dfs2(int v){
	vis[v] = true;
	scc[v] = nscc;
	rep(i, 0, backadj[v].size())
		if (!vis[backadj[v][i]])
			dfs2(backadj[v][i]);
}

int main() {
	cin >> T;
	repe(t, 1, T){
		cin >> n >> m;
		repe(i, 0, n)
			adj[i].clear(),
			backadj[i].clear(),
			scc[i] = -1,
			vis[i] = false;
		order.clear();
		nscc = 0;

		int a, b;
		rep(i, 0, m)
			cin >> a >> b,
			adj[a-1].push_back(b-1),
			backadj[b-1].push_back(a-1);

		rep(i, 0, n)
			if (!vis[i])
				dfs(i);
		rep(i, 0, n)
			vis[i] = false;
		for (int i = n - 1; i >= 0; --i)
			if (!vis[order[i]])
				dfs2(order[i]),
				++nscc;

		rep(i, 0, nscc)
			indeg[i] = outdeg[i] = 0;
		rep(i, 0, n)
			rep(j, 0, adj[i].size())
			if (scc[i] != scc[adj[i][j]])
				indeg[scc[adj[i][j]]]++,
				outdeg[scc[i]]++;
		result = 0;
		int ind = 0, outd = 0;
		rep(i, 0, nscc) {
			if (!indeg[i]) ++ind;
			if (!outdeg[i]) ++outd;
		}
		result = max(ind, outd);

		if (n == 1 || nscc == 1) result = 0;
		printf("Case %d: %d\n", t, result);
	}
	return 0;
}

#endif