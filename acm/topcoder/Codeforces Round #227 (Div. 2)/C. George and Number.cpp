#ifdef do_not_compile_this_file
#include<iostream>
#include<algorithm>
#include<climits>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<deque>
#include<set>
#include<map>
using namespace std;
#define rep(i,f,t) for(int i = (f),end_##i = (t); i < end_##i; ++i)
#define all(v) begin(v),end(v)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

bool lss(vector<char>& a, vector<char>& b){
	if (a.size() != b.size()) return a.size() < b.size();
	return a < b;
}

char a[1000 * 100 + 10];

void __main() {
	cin >> a;
	int n = strlen(a);
	int ans = 1;
	vector<char> so; so.reserve(n);
	so.push_back(a[0]);
	vector<char> cur;
	for (int i = 1; a[i];){
		cur.push_back(a[i]);
		while (a[++i] == '0') cur.push_back(a[i]);
		if (lss(so, cur))
			ans = 1;
		else ++ans;
		for (char cc : cur) so.push_back(cc);
		cur.clear();
	}
	cout << ans << endl;
}

//#define ONLINE_JUDGE
int main(){
#ifndef ONLINE_JUDGE
	FILE* fin = NULL;
	fin = fopen("in.txt", "w+");
	fprintf(fin, "9555\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #1 ...\n\tExpected: ");
	printf("4");
	printf("\tReceived: ");
	__main();
	printf("\n");
	fin = fopen("in.txt", "w+");
	fprintf(fin, "10000000005\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #2 ...\n\tExpected: ");
	printf("2");
	printf("\tReceived: ");
	__main();
	printf("\n");
	fin = fopen("in.txt", "w+");
	fprintf(fin, "800101\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #3 ...\n\tExpected: ");
	printf("3");
	printf("\tReceived: ");
	__main();
	printf("\n");
	fin = fopen("in.txt", "w+");
	fprintf(fin, "45\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #4 ...\n\tExpected: ");
	printf("1");
	printf("\tReceived: ");
	__main();
	printf("\n");
	fin = fopen("in.txt", "w+");
	fprintf(fin, "1000000000000001223300003342220044555\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #5 ...\n\tExpected: ");
	printf("17");
	printf("\tReceived: ");
	__main();
	printf("\n");
	fin = fopen("in.txt", "w+");
	fprintf(fin, "19992000\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #6 ...\n\tExpected: ");
	printf("1");
	printf("\tReceived: ");
	__main();
	printf("\n");
	fin = fopen("in.txt", "w+");
	fprintf(fin, "310200\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #7 ...\n\tExpected: ");
	printf("2");
	printf("\tReceived: ");
	__main();
	printf("\n");
#else
	__main();
#endif

	return 0;
}
#endif
