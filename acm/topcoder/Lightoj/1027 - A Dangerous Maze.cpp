#ifdef do_not_compile_this_file
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<cstring>
#include<climits>
using namespace std;
#define rep(i,f,t) for(int i = (f),end_##i = (t); i < end_##i; ++i)


typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

inline int gcd(int a, int b){
	return b ? gcd(b, a%b) : a;
}
#define _sd(a) scanf("%d", &a)

int main() {
	int t, T; _sd(T);
	for (t = 1; t <= T; ++t){
		int n, sum = 0, pos = 0, tmp; _sd(n);
		rep(i, 0, n) cin >> tmp, sum += abs(tmp), pos += (tmp > 0);
		if (!pos){
			printf("Case %d: inf\n", t);
			continue;
		}
		int g = gcd(sum, pos);
		printf("Case %d: %d/%d\n", t, sum / g, pos / g);
	}
	return 0;
}
#endif