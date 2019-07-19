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


const int mx = 2000 + 10;

int T, child, k;
vector<int> adj[mx], backadj[mx], S[mx];
vector<int> order;
int  scc[mx], mp[mx];
bool vis[mx];
int n, scc_no;
bool ok;

void dfs(int v){
	vis[v] = true;
	rep(i, 0, adj[v].size())
		if (!vis[adj[v][i]])
			dfs(adj[v][i]);
	order.push_back(v);
}

void dfsr(int v){
	vis[v] = true;
	scc[v] = scc_no;
	rep(i, 0, backadj[v].size())
		if (!vis[backadj[v][i]])
			dfsr(backadj[v][i]);
}

void dfs_on_scc(int v){
	if (S[v].size() > 1) {
		ok = false;
		return;
	}
	vis[v] = true;
	if (!S[v].empty()) 
		dfs_on_scc(S[v][0]);
}

int main(){
	cin >> T;
	repe(t, 1, T){
		cin >> child;
		rep(i, 0, mx)
			adj[i].clear(),
			backadj[i].clear(),
			S[i].clear(),
			vis[i] = 0,
			scc[i] = 0,
			mp[i] = -1;
		n = 0;
		int a, b;
		rep(i, 0, child) {
			cin >> k;
			rep(j, 0, k){
				cin >> a >> b;
				if (mp[a] == -1) mp[a] = ++n;
				if (mp[b] == -1) mp[b] = ++n;
				a = mp[a];
				b = mp[b];
				adj[a].push_back(b);
				backadj[b].push_back(a);
			}
		}

		order.clear();
		repe(i, 1, n)
			if (!vis[i])
				dfs(i);

		repe(i, 0, n) vis[i] = false;

		scc_no = 0;
		for (int i = n - 1; i >= 0; --i)
			if (!vis[order[i]])
				++scc_no,
				dfsr(order[i]);

		repe(i, 1, n)
			rep(j, 0, adj[i].size())
			if (scc[i] != scc[adj[i][j]])
				S[scc[i]].push_back(scc[adj[i][j]]);

		repe(i, 0, n) vis[i] = false;
		ok = true;
		dfs_on_scc(scc[mp[0]]);
		repe(i, 1, n)
			if (!vis[scc[i]])
				ok = false;
		printf("Case %d: %s\n", t, (ok ? "YES" : "NO"));
	}
	return 0;
}

#endif