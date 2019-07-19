#ifdef no_compile_tc
// WinterAndReindeers.cpp
#include<algorithm>
#include<iostream>
#include<climits>
#include<cstring>
#include<string>
#include<vector>
#include<sstream>
#include<iterator>
#include<map>
#include<set>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
#define all(v) v.begin(),v.end()
#define rep(i,f,t) for(int i = (f),e_##i = (t); i < e_##i; ++i)

class WinterAndReindeers {
public:
	string cat(vector<string> v){
		stringstream ss;
		copy(all(v), ostream_iterator<string>(ss, ""));
		return ss.str();
	}
	int getNumber(vector <string> allA, vector <string> allB, vector <string> allC)  {
		string a = cat(allA), b = cat(allB), c = cat(allC);
		int I = a.size() + 1, J = b.size() + 1, K = c.size() + 1;
		vvvi v(I, vvi(J, vi(K + 1)));
		rep(i, 1, I)rep(j, 1, J)rep(k, 0, K + 1)
		if (a[i - 1] != b[j - 1])
			v[i][j][k] = max(v[i - 1][j][k], v[i][j - 1][k]),
			v[i][j][k] = max(v[i][j][k], v[i - 1][j - 1][k]);
		else if (a[i - 1] == b[j - 1]){
			if (k == 0)
				v[i][j][k] = max(v[i - 1][j][k], v[i - 1][j - 1][k] + 1),
				v[i][j][k] = max(v[i][j][k], v[i][j - 1][k]);
			else if (k == K)
				v[i][j][k] = v[i - 1][j - 1][k - 1] + 1,
				v[i][j][k] = max(v[i][j][k], v[i - 1][j][k]),
				v[i][j][k] = max(v[i][j][k], v[i][j - 1][k]);
			else{
				if (b[j - 1] == c[k - 1])
					v[i][j][k] = max(v[i - 1][j - 1][k - 1] + 1, v[i][j - 1][k]),
					v[i][j][k] = max(v[i][j][k], v[i - 1][j][k]);
				else
					v[i][j][k] = max(v[i - 1][j - 1][k], v[i - 1][j][k]),
					v[i][j][k] = max(v[i][j][k], v[i][j - 1][k]);
			}
		}
		if (v[I - 1][J - 1][K - 1] == 0) return 0;
		return max(v[I - 1][J - 1][K - 1], v[I - 1][J - 1][K]);
	}


	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "X" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "X", "Y" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "X" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = { "ABCXD" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "BCDEF" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "CD" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(1, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = { "WE", "LOVE" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "WORKING", "FOR", "SANTA" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "JK" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(2, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = { "ABCDE" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "CDEAB" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "B" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(3, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = { "ABCABDEGAXAHDJBAAHFJDXBB", "ABHFHCDALFDJDBBA", "BABBAXAXXX" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "ABLOCBAXBAHAJDXBIJKA", "JBABCDAHKFIUDALPJAH", "AABACX" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "AXBADXBBAB", "CDD" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 23; verify_case(4, Arg3, getNumber(Arg0, Arg1, Arg2)); }

	// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
	WinterAndReindeers ___test;
	___test.run_test(-1);
}

/* PROBLEM STATEMENT

It's winter time! Time to play some games.




Four reindeers are playing the following game.
The first three of them choose three non-empty strings: A, B, and C. (The strings are not necessarily distinct.)
Then, the fourth one (and it happens to be the youngest one) finds a string S that satisfies the following conditions:



S is a subsequence of A. (I.e., either S equals A, or S can be obtained from A by removing some of its characters.)


S is a subsequence of B.


C is a (contiguous) substring of S.


There is no string longer than S that satisfies the previous three conditions.





You are given three vector <string>s allA, allB and allC.
Concatenate all elements of allA, allB and allC to obtain strings A, B and C, respectively.
Return the length of the string S.
If there is no such string, return 0.


DEFINITION
Class:WinterAndReindeers
Method:getNumber
Parameters:vector <string>, vector <string>, vector <string>
Returns:int
Method signature:int getNumber(vector <string> allA, vector <string> allB, vector <string> allC)


CONSTRAINTS
-allA, allB and allC will each contain between 1 and 50 elements, inclusive.
-Each element of allA, allB and allC will contain between 1 and 50 characters, inclusive.
-Each element of allA, allB and allC will consist only of uppercase English letters ('A'-'Z').


EXAMPLES

0)
{"X"}
{"X", "Y"}
{"X"}

Returns: 1

In this case, A = "X", B = "XY", C = "X". The longest possible string that satisfies conditions from the statement is "X". Thus, the answer is 1.

1)
{"ABCXD"}
{"BCDEF"}
{"CD"}

Returns: 3

The longest possible string in this case is "BCD".

2)
{"WE", "LOVE"}
{"WORKING", "FOR", "SANTA"}
{"JK"}

Returns: 0

No string satisfies all criteria in this case. Thus, the answer is 0.

3)
{"ABCDE"}
{"CDEAB"}
{"B"}

Returns: 2



4)
{"ABCABDEGAXAHDJBAAHFJDXBB", "ABHFHCDALFDJDBBA", "BABBAXAXXX"}
{"ABLOCBAXBAHAJDXBIJKA", "JBABCDAHKFIUDALPJAH", "AABACX"}
{"AXBADXBBAB", "CDD"}

Returns: 23


*/
// END CUT HERE
#endif
