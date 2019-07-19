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
using namespace std;
#define all(v) begin(v),end(v)
#define rep(i,f,t) for(int i = (f),end_##i = (t); i < end_##i; ++i)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int mp[256];

int main() {
	ios_base::sync_with_stdio(false);
	for (int i = 'A'; i <= 'Z'; ++i) mp[i] = 0;
	mp['A'] = mp['E'] = mp['O'] = mp['I'] = mp['U'] = 1;
	mp['?'] = 2;
	int t = 0, T; cin >> T;
	while (T--){
		string s; cin >> s;
		int n = s.size();
		vvi dv(n + 1, vi(4)), dc(n + 1, vi(6));
		dv[0][0] = dc[0][0] = 1;
		for (int i = 1; i <= n; ++i){
			int c = mp[s[i - 1]];
			for (int j = 0; j < 3; ++j) if (dv[i - 1][j]){
				if (c == 0 || c == 2) dc[i][1] = 1;
				if (c == 1 || c == 2) dv[i][j + 1] = 1;
			}
			for (int j = 0; j < 5; ++j) if (dc[i - 1][j]){
				if (c == 1 || c == 2) dv[i][1] = 1;
				if (c == 0 || c == 2) dc[i][j + 1] = 1;
			}
		}
		cout << "Case " << ++t << ": ";
		int good = 0, bad = 0;
		for (int i = 1; i <= n; ++i) if (dv[i][3] || dc[i][5]) bad = 1;
		for (int j = 0; j < 3; ++j) if (dv[n][j]) good = 1;
		for (int j = 0; j < 5; ++j) if (dc[n][j]) good = 1;
		if (good && bad)
			cout << "MIXED" << endl;
		else if (good)
			cout << "GOOD" << endl;
		else
			cout << "BAD" << endl;
	}
	return 0;
}
#endif