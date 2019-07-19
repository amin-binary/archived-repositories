/*
ID: amin.ro1
PROG: msquare
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
using namespace std;
#define all(v) v.begin(),v.end()
#define rep(i,f,t) for(int i = (f),end_##i = (t); i < end_##i; ++i)

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
ll get_in(){
	ll ans = 0, tmp;
	rep(i, 0, 8){
		cin >> tmp;
		ans = ans * 10 + tmp;
	}
	int u = ans / 10000, d = ans % 10000;
	int rd = 0;
	while (d) rd *= 10, rd += d % 10, d /= 10;
	return u * 10000 + rd;
}
ll A(ll a){
	return (a / 10000) + (a % 10000) * 10000;
}
ll B(ll a){
	ll u = a / 10000, d = a % 10000;
	u = (u % 10) * 1000 + u / 10;
	d = (d % 10) * 1000 + d / 10;
	return u * 10000 + d;
}
ll arr[8];
ll C(ll a){
	rep(i, 0, 8)
		arr[7 - i] = a % 10,
		a /= 10;
	ll tmp = arr[5];
	arr[5] = arr[6];
	arr[6] = arr[2];
	arr[2] = arr[1];
	arr[1] = tmp;
	ll ans = 0;
	rep(i, 0, 8)
		ans *= 10,
		ans += arr[i];
	return ans;
}

set<ll> saw;

int main() {
	freopen("msquare.in", "r", stdin); freopen("msquare.out", "w", stdout);
	ll a = 12348765;

	ll tar = get_in();

	deque<ll> di; deque<string> ds;
	if (a == tar){
		puts("0");
		cout << endl;
		return 0;
	}
	di.push_back(a);
	string s;
	ds.push_back(s);
	while (true){
		ll g = di.front(); di.pop_front();
		s = ds.front(); ds.pop_front();
		if (saw.count(g)) continue;
		ll a = A(g), b = B(g), c = C(g);
		di.push_back(a); di.push_back(b); di.push_back(c);
		ds.push_back(s + 'A'); ds.push_back(s + 'B'); ds.push_back(s + 'C');
		if (a == tar){
			cout << s.size() + 1 << endl;
			cout << s << 'A' << endl;
			return 0;
		}
		if (b == tar){
			cout << s.size() + 1 << endl;
			cout << s << 'B' << endl;
			return 0;
		}
		if (c == tar){
			cout << s.size() + 1 << endl;
			cout << s << 'C' << endl;
			return 0;
		}
		saw.insert(g);
	}
	return 0;
}
#endif