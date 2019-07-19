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
typedef unsigned char uchar;
	
map<string, vector<string> > mp;
map<string,int> saw;
int T, m, tick;


int vis(const string& str){
	map<string, int>::iterator it = saw.find(str);
	return it == saw.end() ? 0 : it->second;
}

bool have_cyle = false;

void dfs(const string& v){
	saw[v] = tick;
	vector<string>& vec = mp[v];
	for (int i = 0, _end = vec.size(); i < _end; ++i){
		int vis_no = vis(vec[i]);
		if (vis_no == tick){
			have_cyle = true;
			return;
		}
		else if (vis_no == 0)
			dfs(vec[i]);
	}
}

int main() {
	cin >> T;
	repe(t, 1, T){
		cin >> m;
		mp.clear();
		saw.clear();
		string a, b;
		rep(i, 0, m)
			cin >> a >> b,
			mp[a].push_back(b);

		have_cyle = false;
		tick = 0;
		for (map<string, vector<string> >::iterator it = mp.begin(); it != mp.end() && !have_cyle; ++it)
			if (!vis(it->first))
				++tick ,
				dfs(it->first);
		printf("Case %d: %s\n", t, (have_cyle ? "No" : "Yes"));
	}
	return 0;
}

#endif