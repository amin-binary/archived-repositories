/*
ID: amin.ro1
PROG: butter
LANG: C++11
*/
#ifdef do_not_compile_this_file
#include<algorithm>
#include<iostream>
#include<cstring>
#include<climits>
#include<cstdio>
#include<string>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<queue>
#include<functional>
using namespace std;
#define all(v) v.begin(),v.end()
#define rep(i,f,t) for(int i = (f),end_##i = (t); i < end_##i; ++i)

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
int n, p, c;
vi adj[801], cst[801];
int cnt[801], tmp;
int val[801];
bool vis[801];

int main() {
	freopen("butter.in","r",stdin); freopen("butter.out","w",stdout);
	cin >> n >> p >> c;
	rep(i, 0, n) cin >> tmp, ++cnt[tmp];
	rep(i, 0, c){
		int a, b; cin >> a >> b >> c;
		adj[a].push_back(b);
		adj[b].push_back(a);
		cst[a].push_back(c);
		cst[b].push_back(c);
	}
	int ans = INT_MAX;
	rep(u, 1, p + 1){
		priority_queue<ii,vector<ii>,function<bool(const ii&,const ii&)> > pq([](const ii& lhs, const ii& rhs){ return lhs.second > rhs.second; });
		int tot = 0;
		memset(vis, 0, sizeof(vis));
		fill(val, val + 801, INT_MAX);
		pq.push(ii(u, 0));
		while (!pq.empty()){
			ii v = pq.top(); pq.pop();
			if(vis[v.first]) continue;
			vis[v.first] = true;
			tot += v.second * cnt[v.first];
			rep(j, 0, adj[v.first].size()){
				int g = adj[v.first][j];
				int c = v.second + cst[v.first][j];
				if (c < val[g])
					val[g] = c,
					pq.push(ii(g, c));
			}
		}
		ans = min(ans, tot);
	}
	cout << ans << endl;
	return 0;
}
#endif