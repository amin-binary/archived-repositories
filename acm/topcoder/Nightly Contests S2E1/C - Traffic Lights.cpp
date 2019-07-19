#ifdef do_not_compile_this_file
#include<algorithm>
#include<iterator>
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
using namespace std;
#define all(v) v.begin(),v.end()
#define rep(i,f,t) for(int i = (f),end_##i = (t); i < end_##i; ++i)


typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int st, ed;
int n, m;
int inx(char c){
	if (c == 'B') return 1;
	return 2;
}
int tm[305][4]; // tm[0] = remaining,tm[1] = B , tm[2] = P,B or P
vi adj[305];
vi val[305];
int bst[305];
int par[301];
bool vis[301];
char ch;

int blue(int a, int t){
	int ini = tm[a][0];
	int ix = tm[a][3];
	int cur = 0;
	while (cur < t || ix == 2){
		if (ini > t - cur && ix == 1)
			return t;
		cur += ini;
		ix = (ix == 1) ? 2 : 1;
		ini = tm[a][ix];
	}
	return cur;
}
int purple(int a, int t){
	int ini = tm[a][0];
	int ix = tm[a][3];
	int cur = 0;
	while (cur < t || ix == 1){
		if (ini > t - cur && ix == 2)
			return t;
		cur += ini;
		ix = (ix == 1) ? 2 : 1;
		ini = tm[a][ix];
	}
	return cur;
}

int dist(int a, int b, int t){
	int prv = 0;
	do {
		prv = max(blue(a, t), blue(b, t));
		swap(prv, t);
	} while (prv != t);
	return t;
}

struct cmp {
	bool operator()(int a, int b){
		return bst[a] > bst[b];
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	memset(bst, 0x7F, sizeof(bst));
	priority_queue<int, vector<int>, cmp> pq;
	cin >> st >> ed;
	cin >> n >> m;
	rep(i, 1, n + 1){
		cin >> ch;
		cin >> tm[i][0] >> tm[i][1] >> tm[i][2];
		tm[i][3] = inx(ch);
	}
	rep(i, 0, m){
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(b);
		adj[b].push_back(a);
		val[a].push_back(c);
		val[b].push_back(c);
	}
	bst[st] = 0;
	pq.push(st);
	while (!pq.empty()){ 
		int v = pq.top(); pq.pop();
		vis[v] = true;
		for (int i = 0; i < adj[v].size(); ++i) if(!vis[adj[v][i]]){
			int u = adj[v][i];
			int nt = dist(v, u, bst[v]);
			//int tv = 0;
			//while (tv < val[v][i]){
			//	int tmp = min(purple(v, nt), purple(u, nt));
			//	tv += tmp - nt;
			//	nt = dist(v, u, tmp);
			//}
			nt = blue(u, nt + val[v][i]);
			//nt += tv;
			if (nt < bst[u]){
				bst[u] = nt;
				par[u] = v;
				pq.push(u);
			}
		}
	}
	cout << bst[ed] << endl;
	return 0;
}
#endif