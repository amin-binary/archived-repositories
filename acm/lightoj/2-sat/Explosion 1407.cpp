#ifndef no_compile // still getting wrong answer :(

//#include <functional>
//#include <algorithm>
//#include <iostream>
//#include <iterator>
//#include <numeric>
//#include <sstream>
//#include <fstream>
//#include <cstdlib>
//#include <cstring>
//#include <climits>
//#include <cstdio>
//#include <vector>
//#include <cfloat>
//#include <stack>
//#include <deque>
//#include <queue>
//#include <cmath>
//#include <list>
//#include <set>
//#include <map>
//#define X first
//#define Y second
//#define rep(i,m,n) for(int i=(m);i<(int)(n);++i)
//#define contain(con,val) (find(con.begin(),con.end(),(val)) != con.end())
//#define foreach(it,c,type) for(type::iterator it=c.begin(),End=c.end();it!=End;++it)
//#define rforeach(rit,c,type) for(type::reverse_iterator rit=c.rbegin(),rEnd=c.rend();rit!=rEnd;++it)
//using namespace std;
//typedef pair<int, int> prii; typedef pair<string, int> prsi;

//int t, n, m, k;
//int x, y, z, type;
//vector<int> adj[1000 * 2 + 10], backadj[1000 * 2 + 10];
//#define Not(a) (((a)-n)*-1 + n)
//int council[5 + 1][3 + 1];
//bool saw[1000 * 2 + 10];
//vector<int> order;
//int vis_rnd[1000 * 2 + 10], rnd;
//int sign[1000 * 2 + 10];
//
//
//void dfs(int v){
//	saw[v] = true;
//	for (int i = 0, _end = adj[v].size(); i < _end; ++i)
//		if (!saw[adj[v][i]])
//			dfs(adj[v][i]);
//	order.push_back(v);
//}
//void backdfs(int v){
//	saw[v] = true;
//	vis_rnd[v] = rnd;
//	if (sign[v] == 0)
//		sign[v] = -1,
//		sign[Not(v)] = +1;
//	for (int i = 0, _end = backadj[v].size(); i < _end; ++i)
//		if (!saw[backadj[v][i]])
//			backdfs(backadj[v][i]);
//}
//
//int main() {
//	cin >> t;
//	for (int Case = 1; Case <= t; ++Case){
//
//		cin >> n >> m >> k;
//		for (int i = 0; i <= 2 * n; ++i)
//			adj[i].clear(),
//			backadj[i].clear(),
//			sign[i] = 0,
//			vis_rnd[i] = 0;
//		rnd = 0;
//		order.clear();
//
//		for (int i = 0; i < m; ++i){
//			cin >> type >> x >> y;
//			x += n, y += n;
//			if (type == 1)
//				adj[Not(x)].push_back(y),
//				adj[Not(y)].push_back(x),
//				backadj[y].push_back(Not(x)),
//				backadj[x].push_back(Not(y));
//			if (type == 2)
//				adj[Not(x)].push_back(Not(y)),
//				backadj[Not(y)].push_back(Not(x));
//			if (type == 3)
//				adj[x].push_back(Not(y)),
//				adj[y].push_back(Not(x)),
//				backadj[Not(y)].push_back(x),
//				backadj[Not(x)].push_back(y);
//			if (type == 4)
//				adj[x].push_back(Not(y)),
//				adj[Not(y)].push_back(x),
//				adj[y].push_back(Not(x)),
//				adj[Not(x)].push_back(y),
//				backadj[x].push_back(Not(y)),
//				backadj[Not(y)].push_back(x),
//				backadj[y].push_back(Not(x)),
//				backadj[Not(x)].push_back(y);
//		}
//		for (int i = 0; i < k; ++i) {
//			for (int j = 0; j < 4; ++j) cin >> council[i][j];
//			for (int j = 1; j < 4; ++j) council[i][j] += n;
//		}
//		deque<int> que;
//		for (int p = 0; p < k; ++p){
//			for (int i = 0; i < k; ++i){
//				for (int j = 1; j < 4; ++j){
//					// clean up
//					for (int q = 0; q <= 2*n; ++q)
//						saw[q] = false;
//
//					//init que	
//					if (council[i][0] == 1)
//						que.push_front(Not(council[i][j])),
//						saw[Not(council[i][j])] = true;
//					if (council[i][0] == 2)
//						que.push_front(council[i][j]),
//						saw[council[i][j]] = true;
//
//					int tmp;
//					while (!que.empty()){
//						tmp = que.back();
//						que.pop_back();
//						for (int q = 0, _end = adj[tmp].size(); q < _end; ++q)
//							if (!saw[adj[tmp][q]])
//								saw[adj[tmp][q]] = true,
//								que.push_front(adj[tmp][q]);
//					}
//
//					for (int q = 1; q < 4; ++q) {
//						if (council[i][0] == 1 && q != j && saw[Not(council[i][q])])
//							adj[Not(council[i][j])].push_back(council[i][1 + 2 + 3 - j - q]),
//							backadj[council[i][1 + 2 + 3 - j - q]].push_back(Not(council[i][j]));
//						if (council[i][0] == 2 && q != j && saw[council[i][q]])
//							adj[council[i][j]].push_back(Not(council[i][1 + 2 + 3 - j - q])),
//							backadj[Not(council[i][1 + 2 + 3 - j - q])].push_back(council[i][j]);
//					}
//				}
//			}
//		}
//
//		for (int i = 0; i <= 2 * n; ++i) saw[i] = false;
//		for (int i = 0; i < 2 * n; ++i)
//			if (!saw[i] && i != n)
//				dfs(i);
//		for (int i = 0; i <= 2 * n; ++i) saw[i] = false;
//		for (int i = order.size() - 1; i >= 0; --i)
//			if (!saw[order[i]])
//				++rnd,
//				backdfs(order[i]);
//		bool is_possible = true;
//		int cnt = 0;
//		for (int i = 0; i < n && is_possible; ++i) {
//			if (vis_rnd[i] == vis_rnd[Not(i)])
//				is_possible = false;
//			if (sign[i] == -1)
//				++cnt;
//		}
//		if (!is_possible)
//			cout << "Case " << Case << ": Impossible." << endl;
//		else {
//			cout << "Case " << Case << ": Possible " << cnt;
//			for (int i = n-1; i >= 0; --i)
//				if (sign[i] == -1)
//					cout << ' ' << Not(i) - n;
//			cout << "." << endl;
//		}
//		
//	}
//	return 0;
//}
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

const int mx = 2 * 1000 + 10;

int T, n, m, k;
#define Not(a) (((a)-1)*2 + 1)
#define Val(a) (((a)-1)*2)
#define Org(a) ((a)/2 + 1)

struct sat3 { int x, y, z, type; };

vector<int> adj[mx], backadj[mx];
vector<int> order;
int scc[mx];
set<int> member;
int pw[20];
sat3 oracle[5 + 1];

bool check(){
	vector<int> vec(member.begin(), member.end());
	pw[0] = 1;
	repe(i, 1, vec.size())
		pw[i] = pw[i - 1] * 2;
	sat3 sat;
	rep(i, 0, pw[vec.size()]){
		rep(j, 0, k){
			sat = oracle[j];
			if (sat.type == 1){

			}
		}
	}
}

int main(){
	return 0;
}

#endif