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

const int mx = 10 * 1000 + 10;

int T, n, m;
bool saw[mx];
vector<int> order;
vector<int> adj[mx];

void dfs(int v){
	saw[v] = true;
	rep(i, 0, adj[v].size())
		if (!saw[adj[v][i]])
			dfs(adj[v][i]);
	order.push_back(v);
}

int main() {
	cin >> T;
	repe(t, 1, T){
		cin >> n >> m;
		repe(i, 1, n) saw[i] = false, adj[i].clear();
		order.clear();
		int a, b;
		rep(i, 0, m)
			cin >> a >> b,
			adj[a].push_back(b);
		repe(i, 1, n)
			if (!saw[i])
				dfs(i);
		repe(i, 1, n) saw[i] = false;
		int result = 0;
		for (int i = n - 1; i >= 0; --i)
			if (!saw[order[i]])
				++result,
				dfs(order[i]);
		printf("Case %d: %d\n", t, result);
	}
	return 0;
}

#endif