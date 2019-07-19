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

char str[25];
ll dp[25];

void print_perm(char *s, ll len, ll n){
	if (n == 1){ printf(s); return; }
	int cnt[26] = {};
	ll num = 1, den = 1;
	int c;
	for (int i = len - 1, j = 1; i >= 0; --i, ++j){
		c = s[i] - 'a';
		den *= ++cnt[c];
		num *= j;
		dp[i] = num / den;
	}

	if (dp[0] < n) { printf("Impossible"); return; }
	int i = 0;
	while (i + 1 < len && dp[i + 1] >= n) putchar(s[i++]);

	int j = i + 1;
	while (s[i] >= s[j]) ++j;
	swap(s[i], s[j]);
	print_perm(s + i, len - i, n - dp[i + 1]);
}
int main() {
	ll t, T, n, len;
	scanf("%d", &T);
	for (t = 1; t <= T; ++t)
		scanf("%s %d", str, &n),
		len = strlen(str),
		sort(str, str + len),
		printf("Case %d: ", t),
		print_perm(str, len, n),
		putchar('\n');
	return 0;
}
#endif