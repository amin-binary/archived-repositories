#ifdef no_compile_tc
// ErasingCharacters.cpp
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,from,to) for(int i = (from),end##i = (to); i < end##i; ++i)

class ErasingCharacters { 
public: 
	bool shorten(string& s){
		string t;
		bool ok = false;
		for (int i = 0; i < s.size();) {
			if (i+1 < s.size() && s[i] == s[i + 1] && !ok)
				i += 2,
				ok = true;
			else
				t.push_back(s[i]),
				++i;
		}
		s = t;
		return ok;
	}
	string simulate(string s)  { 
		while (shorten(s))
			;
		return s;
	} 


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "cieeilll"; string Arg1 = "cl"; verify_case(0, Arg1, simulate(Arg0)); }
	void test_case_1() { string Arg0 = "topcoder"; string Arg1 = "topcoder"; verify_case(1, Arg1, simulate(Arg0)); }
	void test_case_2() { string Arg0 = "abcdefghijklmnopqrstuvwxyyxwvutsrqponmlkjihgfedcba"; string Arg1 = ""; verify_case(2, Arg1, simulate(Arg0)); }
	void test_case_3() { string Arg0 = "bacaabaccbaaccabbcabbacabcbba"; string Arg1 = "bacbaca"; verify_case(3, Arg1, simulate(Arg0)); }
	void test_case_4() { string Arg0 = "eel"; string Arg1 = "l"; verify_case(4, Arg1, simulate(Arg0)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE
int main()
	{
	ErasingCharacters ___test; 
	 ___test.run_test(-1); 
} 

/* PROBLEM STATEMENT
Fox Ciel received a string as a birthday present.
However, the string was too long for her, so she decided to make it shorter by erasing some characters.
The erasing process will look as follows:
Find the smallest i such that the i-th character and the (i+1)-th character of the string are same.
If there is no such i, end the process.
Remove the i-th and the (i+1)-th character of the string, and repeat from 1.



For example, if she receives "cieeilll", she will change the string as follows: "cieeilll" -> "ciilll" -> "clll" -> "cl". You are given a string s. Return the string she will get after she erases characters as described above.

DEFINITION
Class:ErasingCharacters
Method:simulate
Parameters:string
Returns:string
Method signature:string simulate(string s)


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive.
-Each character in s will be a lowercase letter ('a'-'z').


EXAMPLES

0)
"cieeilll"

Returns: "cl"

This is the example from the statement.

1)
"topcoder"

Returns: "topcoder"

She won't erase any characters at all.

2)
"abcdefghijklmnopqrstuvwxyyxwvutsrqponmlkjihgfedcba"

Returns: ""



3)
"bacaabaccbaaccabbcabbacabcbba"

Returns: "bacbaca"



4)
"eel"

Returns: "l"


 */
// END CUT HERE
#endif
