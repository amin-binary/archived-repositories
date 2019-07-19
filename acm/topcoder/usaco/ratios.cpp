/*
ID: amin.ro1
PROG: ratios
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
struct mix{
	int x, y, z;
	mix() : x(0), y(0), z(0) { }
	mix(int X, int Y, int Z) : x(X), y(Y), z(Z){}

	mix& operator +=(const mix& m){
		x += m.x;
		y += m.y;
		z += m.z;
		return *this;
	}
	mix operator *(int n){
		return mix(n*x, n*y, n*z);
	}
	mix operator +(mix& m){
		return mix(m.x + x, m.y + y, m.z + z);
	}
	mix operator +(mix&& m){
		return mix(m.x + x, m.y + y, m.z + z);
	}

	int mul(const mix& m){
		if ((m.x && x%m.x) || (m.y && y%m.y) || (m.z && z%m.z)) return 0;
		if ((m.x && m.y && x / m.x != y / m.y) || (m.y && m.z && y / m.y != z / m.z) || (m.z && m.x && z / m.z != x / m.x)) return 0;
		return m.x ? x / m.x : m.y ? y / m.y : z / m.z;
	}
	int sum() {
		return x + y + z;
	}
};
void get(mix& m){
	scanf("%d%d%d", &m.x, &m.y, &m.z);
}

mix dp[100][100][100];

int main() {
	freopen("ratios.in", "r", stdin); freopen("ratios.out", "w", stdout);
	mix t, a, b, c;
	get(t); get(a); get(b); get(c);
	int bst = INT_MAX, rst; mix mst;
	rep(i, 0, 100) rep(j, 0, 100) rep(k, 0, 100) {
		//if (i){ dp[i][j][k] = dp[i - 1][j][k]; dp[i][j][k] += a; }
		//else if (j){ dp[i][j][k] = dp[i][j - 1][k]; dp[i][j][k] += b; }
		//else if (k) { dp[i][j][k] = dp[i][j][k - 1]; dp[i][j][k] += c; }
		mix mx = a*i + b*j + c*k;
		int m = mx.mul(t),
			v = mx.sum();
		if (m && v < bst){
			bst = v, rst = m, mst.x = i, mst.y = j, mst.z = k;
			printf("%d %d %d %d\n", mst.x, mst.y, mst.z, rst);
			return 0;
		}

	}
	if (bst == INT_MAX)
		puts("NONE");
	else
		printf("%d %d %d %d\n", mst.x, mst.y, mst.z, rst);
	return 0;
}
#endif