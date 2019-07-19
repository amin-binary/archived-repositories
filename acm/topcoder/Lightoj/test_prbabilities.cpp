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

int main() {
	double p = 1;
	rep(i, 1, 40)
		p *= (1000 - i) / (1000.0 - i + 1);
	printf("%.8f\n", p);
	//cout << p << endl;
	return 0;
}
#endif