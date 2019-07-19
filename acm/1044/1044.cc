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

void prob_1044();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); prob_1044(); return 0;
}

void prob_1044() {
    int T; cin >> T;
    repe(t,1,T){
        string s; cin >> s;
        int n = s.size();
        int dp[1000] = { };
        bool is_pal[1000][1000] = { };
        rep(i,0,n) {
            dp[i] = i+1;
            repe(j,0,i) {
                if(s[j] == s[i] && (i-j <= 1 || is_pal[j+1][i-1])) {
                    is_pal[j][i] = true;
                    dp[i] = min(dp[i], 1 + (j ? dp[j-1] : 0));
                }
            }

        }
        cout << "Case " << t << ": " << dp[n-1] << endl;
    }
}

/*******************************
* A palindrome partition is the partitioning of a string such
* that each separate substring is a palindrome.
* For example, the string "ABACABA" could be
* partitioned in several different ways, such as {"A","B","A","C","A","B","A"},
* {"A","BACAB","A"},
* {"ABA","C","ABA"}, or {"ABACABA"},
* among others.
* You are given a string s. Return the minimum possible
* number of substrings in a palindrome partition of s.
*
* Input
* Input starts with an integer T (≤ 40),
* denoting the number of test cases.
* Each case begins with a non-empty string s of uppercase
* letters with length no more than 1000.
*
* Output
* For each case of input you have to print the case number and
* the desired result.
***/
