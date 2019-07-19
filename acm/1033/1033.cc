// author: amin.roosta89@gmail.com
#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <cmath>
#include <list>
#include <map>
#include <set>

#define rep(i,f,t)  for(int i = f; i < t; ++i)
#define repe(i,f,t) for(int i = f; i <= t; ++i)
#define all(v)      v.begin(), v.end()

using namespace std;
using ii = pair<int, int>;
using vi = vector<int>;

void prob_1033();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); prob_1033(); return 0;
}

void prob_1033() {
    int T; cin >> T;
    repe(t,1,T){
        string s; cin >> s;
        int dp[100][100] = {};
        int n = s.length();
        rep(j,0,n)
            rep(i,0,n-j) {
                if(j==0) dp[i][i] = 1;
                else if(s[i] != s[i+j])
                    dp[i][i+j] = max(dp[i+1][i+j], dp[i][i+j-1]);
                else
                    dp[i][i+j] = 2 + dp[i+1][i+j-1];
            }
        cout << "Case " << t << ": " << n - dp[0][n-1] << endl;
    }
}

/*******************************
* By definition palindrome is a string which is not changed
* when reversed. "MADAM" is a nice example of palindrome. It is
* an easy job to test whether a given string is a palindrome or not. But it may
* not be so easy to generate a palindrome.
* Here we will make a palindrome generator which will take an
* input string and return a palindrome. You can easily verify that for a string
* of length n, no more than (n - 1) characters are required to make
* it a palindrome. Consider "abcd" and its palindrome "abcdcba"
* or "abc" and its palindrome "abcba". But life
* is not so easy for programmers!! We always want optimal cost. And you have to
* find the minimum number of characters required to make a given string to a
* palindrome if you are only allowed to insert characters at any position of the
* string.
* Input
* Input starts with an integer T (≤ 200),
* denoting the number of test cases.
* Each case contains a string of lowercase letters denoting
* the string for which we want to generate a palindrome. You may safely assume
* that the length of the string will be positive and no more than 100.
* Output
* For each case, print the case number and the minimum number
* of characters required to make string to a palindrome.
***/
