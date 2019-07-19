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
#include<deque>
using namespace std;
#define all(v) begin(v),end(v)
#define rep(i,f,t) for(int i = (f),end_##i = (t); i < end_##i; ++i)


typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int a[101], b[101], n, prv = -1, od, bd, cnt[7], ont[7];
bool vis[101];
bool org[101];

#define rot(i)  swap(a[i], b[i])

int main(){
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	rep(i, 0, n) cin >> a[i] >> b[i], ++cnt[a[i]], ++cnt[b[i]];
	rep(i, 0, 7) od += cnt[i] % 2, ont[i] = cnt[i]%2;
	if (od > 2){ cout << "No solution" << endl; return 0; }
	if (n > 1) rep(i, 0, n) if (cnt[a[i]] == 1 && cnt[b[i]] == 1) { cout << "No solution" << endl; return 0; }

#define bad(i) ((cnt[a[i]] == 1 || cnt[b[i]] == 1) && n > 2)
#define badv(v) (dq.size() + 2 < n ? (cnt[v] == 1) : (ont[v] != 1))

	deque<int> dq;
	while (dq.size() != n){
		rep(i, 0, n)
		if (!vis[i]){
			if (dq.empty() && !bad(i)) vis[i] = true, dq.push_back(i), --cnt[a[i]], --cnt[b[i]];
			else if (!dq.empty()){
				int u = dq.back();
				int v = dq.front();
				if (b[u] == a[i] && !badv(b[i]))vis[i] = true, dq.push_back(i), --cnt[a[i]], --cnt[b[i]];
				else if (b[u] == b[i] && !badv(a[i]))vis[i] = true, dq.push_back(i), --cnt[a[i]], --cnt[b[i]], rot(i), org[i] = true;
				else if (a[v] == b[i] && !badv(a[i])) vis[i] = true, dq.push_front(i), --cnt[a[i]], --cnt[b[i]];
				else if (a[v] == a[i] && !badv(b[i]))vis[i] = true, dq.push_front(i), --cnt[a[i]], --cnt[b[i]], rot(i), org[i] = true;
			}
		}
		;
	}
	for (int i = 0; i < dq.size(); ++i)
		cout << dq[i] + 1 << ' ' << char(org[i] ? '-' : '+') << endl;

	return 0;
}
#endif