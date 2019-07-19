#ifdef no_compile // Getting Wrong Answer :(

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


const short mx = 5 * 1000 + 10;

short T, n, m;
vector<short> adj[mx];
short mp[mx], pos[mx], backmp[mx];
short saw[mx];
vector<short> order;
vector<short> parent[mx];
vector< pair<short, short> > result;
short turn;

bool my_cmp(short a, short b){
	return pos[a] > pos[b];
}

void dfs(short v){
	saw[v] = true;
	rep(i, 0, adj[v].size())
		if (!saw[adj[v][i]])
			dfs(adj[v][i]);

	pos[v] = order.size();
	order.push_back(v);
}

vector<short> stk;

void dfs2(short v){
	saw[v] = true;
	rep(i, 0, adj[v].size())
		if (!saw[adj[v][i]])  {
			parent[adj[v][i]].push_back(v);
			result.push_back(make_pair(backmp[v], backmp[adj[v][i]])),
				dfs2(adj[v][i]);
		}
		else {
			bool ok = true;
			stk.clear();
			short u = adj[v][i];
			stk.push_back(u);
			while (ok && !stk.empty())
			{
				int tmp = stk.back(); stk.pop_back();
				if (tmp == v){
					ok = false;
					continue;
				}
				rep(jj, 0, parent[tmp].size())
					stk.push_back(parent[tmp][jj]);
			}
			if (ok)
				result.push_back(make_pair(backmp[v], backmp[adj[v][i]])),
				parent[u].push_back(v);
		}
}

int main() {
	cin >> T;
	repe(t, 1, T){
		cin >> n >> m;
		repe(i, 0, n)
			adj[i].clear(),
			mp[i] = -1,
			backmp[i] = -1,
			saw[i] = 0,
			parent[i].clear(),
			pos[i] = -1;
		short a, b, cnt = 0;
		rep(i, 0, m){
			cin >> a >> b;
			if (mp[a] == -1) mp[a] = cnt++, backmp[mp[a]] = a;
			if (mp[b] == -1) mp[b] = cnt++, backmp[mp[b]] = b;
			a = mp[a];
			b = mp[b];
			adj[a].push_back(b);
		}
		order.clear();
		n = cnt;
		rep(i, 0, n)
			if (!saw[i])
				dfs(i);
		rep(i, 0, n)
			saw[i] = 0,
			sort(adj[i].begin(), adj[i].end(), my_cmp);

		result.clear();
		turn = 0;
		for (short i = n - 1; i >= 0; --i)
			if (!saw[order[i]])
				++turn,
				dfs2(order[i]);
		printf("Case %d: %d\n", t, result.size());

		sort(result.begin(), result.end());
		for (vector< pair<short, short> >::iterator it = result.begin(); it != result.end(); ++it)
			cout << it->first << ' ' << it->second << endl;
	}
	return 0;
}

#endif