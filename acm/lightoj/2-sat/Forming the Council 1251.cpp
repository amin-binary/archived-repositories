#ifdef do_compile // Successfully Accepted :)

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



int			t, n, m;
vector<int> adj[8 * 1000 * 2 + 10];
vector<int> backadj[8 * 1000 * 2 + 10];
bool		saw[8 * 1000 * 2 + 10];
int		sign[8 * 1000 * 2 + 10];
int		visit_round[8 * 1000 * 2 + 10], rnd;
vector<int> order;

void dfs(int v){
	saw[v] = true;
	for (int i = 0, u, _end = adj[v].size(); i < _end; ++i) {
		u = adj[v][i];
		if (!saw[u])
			dfs(u);
	}
	order.push_back(v);
}

void backdfs(int v){
	visit_round[v] = rnd;
	saw[v] = true;
	if (sign[v] == 0)
		sign[v] = -1,
		sign[(v - m)*-1 + m] = +1;
	//for (auto u : backadj[v])
	for (int i = 0, u, _end = backadj[v].size(); i < _end; ++i) {
		u = backadj[v][i];
		if (!saw[u])
			backdfs(u);
	}
}

int main() {
	cin >> t;
	for (int number = 1; number <= t; ++number){
		cin >> n >> m;
		// clean up
		for (int i = 0; i <= 2 * m; ++i)
			adj[i].clear(),
			backadj[i].clear(),
			saw[i] = false,
			sign[i] = 0;
		rnd = 0;
		order.clear();

		int a, b;
		for (int i = 0; i < n; ++i)
			cin >> a >> b,
			a += m, b += m,
			adj[(a - m)*-1 + m].push_back(b),
			adj[(b - m)*-1 + m].push_back(a),
			backadj[a].push_back((b - m)*-1 + m),
			backadj[b].push_back((a - m)*-1 + m);

		for (int i = 0; i <= 2 * m; ++i)
			if (!saw[i] && i != m)
				dfs(i);
		for (int i = 0; i <= 2 * m; ++i)
			saw[i] = false;
		bool have_solution = true;
		for (vector<int>::reverse_iterator it = order.rbegin(); it < order.rend(); ++it){
			int v = *it;
			if (!saw[v])
				++rnd,
				backdfs(v);
		}
		for (int i = 0; i < m; ++i){
			if (visit_round[i] == visit_round[(i - m)*-1 + m])
				have_solution = false;
		}


		if (!have_solution)
			cout << "Case " << number << ": No" << endl;
		else{
			cout << "Case " << number << ": Yes" << endl;
			int cnt = 0;
			for (int i = 0; i < m; ++i)
				if (sign[i] == -1)
					++cnt;
			cout << cnt;
			for (int i = m - 1; i >= 0; --i)
				if (sign[i] == -1)
					cout << ' ' << (i - m)*-1;
			cout << endl;
		}
	}
	return 0;
}
#endif