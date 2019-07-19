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

struct tt{
	int x, y;
	tt(int a, int b) : x(a), y(b){}
};

tt operator+(const tt& a, const tt& b){
	int h = a.x + b.x;
	int m = a.y + b.y;
	h += m / 60;
	m %= 60;
	h %= 24;
	return tt(h, m);
}

bool operator==(const tt& a, const tt& b){
	return a.x == b.x && a.y == b.y;
}


void __main() {
	int a, b, c, d;
	scanf("%d:%d%d:%d", &a, &b, &c, &d);
	tt s(a, b), du(c, d);
	rep(h,0,24)
		rep(m,0,60)
	if ((tt(h, m) + du) == s){
		printf("%.2d:%.2d\n",h,m);
		return ;
	}
	return ;
}

//#define ONLINE_JUDGE
int main(){
#ifndef ONLINE_JUDGE
	FILE* fin = NULL;
	fin = fopen("in.txt", "w+");
	fprintf(fin, "05:50\n05:44\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #1 ...\n\tExpected: ");
	printf("00:06\n");
	printf("\tReceived: ");
	__main();
	printf("\n");
	fin = fopen("in.txt", "w+");
	fprintf(fin, "00:00\n01:00\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #2 ...\n\tExpected: ");
	printf("23:00\n");
	printf("\tReceived: ");
	__main();
	printf("\n");
	fin = fopen("in.txt", "w+");
	fprintf(fin, "00:01\n00:00\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #3 ...\n\tExpected: ");
	printf("00:01\n");
	printf("\tReceived: ");
	__main();
	printf("\n");
#else
	__main();
#endif

	return 0;
}
#endif
