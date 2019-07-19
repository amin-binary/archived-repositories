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

const int mx = 200 + 10;
const int inf = INT_MAX;

int t, n, m, cs;
int busy[mx];
int dist[mx], dist2[mx];
vector< pair<int, int> > edg;

int main() {
	cin >> t;
	for (cs = 1; cs <= t; ++cs){
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> busy[i],
			dist[i] = dist2[i] = inf;
		cin >> m;
		edg.clear();
		int a, b;
		for (int i = 0; i < m; ++i)
			cin >> a >> b,
			edg.push_back(make_pair(a, b));

		dist[1] = dist2[1] = 0;
		for (int i = 0; i < n - 1; ++i)
			for (int j = 0; j < m; ++j)
			{
				int v = edg[j].first, u = edg[j].second;
				int w = busy[u] - busy[v];
				w = w*w*w;
				if (dist[v] != inf && dist[u] > dist[v] + w)
					dist2[u] = dist[u] = dist[v] + w;
			}
		for (int i = 0; i < n - 1; ++i)
			for (int j = 0; j < m; ++j)
			{
				int v = edg[j].first, u = edg[j].second;
				int w = busy[u] - busy[v];
				w = w*w*w;
				if (dist2[v] != inf && dist2[u] > dist2[v] + w)
					dist2[u] = dist2[v] + w;
			}
		int q;
		cout << "Case " << cs << ":" << endl;
		cin >> q;
		int c;
		for (int i = 0; i < q; ++i){
			cin >> c;
			if (dist[c] != inf && dist[c] >= 3 && dist[c] == dist2[c])
				cout << dist[c] << endl;
			else
				cout << '?' << endl;
		}
	}
	return 0;
}

#endif