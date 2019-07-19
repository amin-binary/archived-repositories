//#ifndef do_not_compile_this_file
//#include<iostream>
//#include<algorithm>
//#include<climits>
//#include<cstring>
//#include<cstdio>
//#include<string>
//#include<vector>
//#include<deque>
//#include<set>
//#include<map>
//using namespace std;
//#define rep(i,f,t) for(int i = (f),end_##i = (t); i < end_##i; ++i)
//#define all(v) begin(v),end(v)
//
//typedef long long ll;
//typedef vector<int> vi;
//typedef pair<int, int> ii;
//int a[1000 * 1000 + 10];
//bool ok[1000 * 1000 + 10];
//int dp[1000 * 1000 + 10];
//int mp[1000 * 1000 + 10];
//
//void __main() {
//	memset(dp, 0, sizeof(dp));
//	memset(ok, 0, sizeof(ok));
//	int n, k; cin >> n >> k;
//	rep(i, 1, n + 1){
//		cin >> a[i];
//		mp[a[i]] = i;
//	}
//	int tmp;
//	rep(j, 0, k){
//		cin >> tmp;
//		ok[mp[tmp]] = true;
//	}
//	ll ans = 0;
//	int bef, cst;
//	bef = -1, cst = 0;
//	rep(i, 1, n + 1){
//		if (ok[i]){
//			if (bef >= a[i])
//				bef = a[i],
//				++cst;
//			else
//				bef = a[i],
//				cst = 1;
//		}
//		if (bef >= a[i])
//			dp[i] += cst;
//	}
//	bef = -1; cst = 0;
//	for (int i = n; i >= 1; --i){
//		if (ok[i]){
//			if (bef >= a[i])
//				bef = a[i],
//				++cst;
//			else
//				cst = 1,
//				bef = a[i];
//		}
//		if (bef >= a[i])
//			dp[i] += cst;
//	}
//
//
//	bef = -1, cst = 0;
//	rep(i, 1, n + 1){
//		if (!ok[i]){
//			if (bef >= a[i])
//				bef = a[i],
//				++cst;
//			else
//				bef = a[i],
//				cst = 1;
//		}
//		if (bef >= a[i])
//			dp[i] += cst;
//	}
//	bef = -1; cst = 0;
//	for (int i = n; i >= 1; --i){
//		if (!ok[i]){
//			if (bef >= a[i])
//				bef = a[i],
//				++cst;
//			else
//				cst = 1,
//				bef = a[i];
//		}
//		if (bef >= a[i])
//			dp[i] += cst;
//	}
//
//	rep(i, 1, n + 1)
//	if (!ok[i])
//		ans += dp[i] - 1;
//
//	cout << ans << endl;
//}
//
////#define ONLINE_JUDGE
//int main(){
//#ifndef ONLINE_JUDGE
//	FILE* fin = NULL;
//	fin = fopen("in.txt", "w+");
//	fprintf(fin, "3 2\n2 1 3\n1 3\n");
//	fclose(fin);
//	freopen("in.txt", "r", stdin);
//	printf("Test Case #1 ...\n\tExpected: ");
//	printf("1\n");
//	printf("\tReceived: ");
//	__main();
//	printf("\n");
//	fin = fopen("in.txt", "w+");
//	fprintf(fin, "10 5\n1 2 3 4 5 6 7 8 9 10\n2 4 6 8 10\n");
//	fclose(fin);
//	freopen("in.txt", "r", stdin);
//	printf("Test Case #2 ...\n\tExpected: ");
//	printf("30\n");
//	printf("\tReceived: ");
//	__main();
//	printf("\n");
//#else
//	__main();
//#endif
//
//	return 0;
//}
//#endif
//#include<iostream>
//#include<string>
//
//using namespace std;
//
//
//string s, q, s1, s2, s3;
//int sum;
//
//int f(string s)
//{
//
//	int n = s.size();
//	cout << "n " << n << endl << s << endl;
//	if (n == 1)
//		return 1;
//	if (n % 2 == 0)
//	{
//		s1 = s.substr(0, n / 2);
//		s2 = s.substr(n / 2);
//		if (s1 < s2)
//		{
//			s1 += s2[0];
//			s2.erase(0, 1);
//		}
//	}
//	else
//	{
//		s1 = s.substr(0, n / 2 + 1);
//		s2 = s.substr(n / 2 + 1);
//	}
//
//	while (s2[0] == '0')
//	{
//		s1 += "0";
//		s2.erase(0, 1);
//	}
//
//	cout << "s1  " << s1 << endl << "s2  " << s2 << "f" << endl;
//
//	if (s2 == "")
//		return 1;
//	int x = f(s1);
//	int y = f(s2);
//	x += y;
//	return x;
//}
//
//int main()
//{
//
//	cin >> s;
//	cout << f(s) << endl;
//
//	return 0;
//}
//
//
