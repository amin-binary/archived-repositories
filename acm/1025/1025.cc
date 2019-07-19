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
 
void prob_1025();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); prob_1025(); return 0;
}
 
void prob_1025() {
    int T; cin >> T;
    repe(t, 1, T) {
        string s; cin >> s;
        long long dp[61][61] = { };
        // aba => a..,.b.,..a,a.a,aba
        // aaa => a..,.a.,..a,a.a, aaa, .aa, aa.
        // dp[i][j] >= (j-i+1)
        // abaca
        // j >= i
        //
        // dp[i][j] = i == j ? 1 :
        //                     dp[i+1][j-1]*2 +        
        //                     dp[i+1][j] - (j-i) +
        //                     dp[i][j-1] - (j-i) +
        //                     3;
        //
        // dp[i][j] = max(dp[i+1][j], dp[i][j-1]) + 1; (s[i] != s[j])
        // dp[0][5] => dp[1][4], dp[0,4], dp[1,5]
        // [1][6][A][ ][ ]
        // [ ][2][7][B][ ]
        // [ ][ ][3][8][C]
        // [ ][ ][ ][4][9]
        // [ ][ ][ ][ ][5]
        rep(i, 0, s.size()) {
            for(int j = 0; j+i < s.size(); ++j) {
                int I = j;
                int J = i+j;
                if(I == J) dp[I][I] = 1;
                else if(s[I] != s[J])
                    dp[I][J] =
                        dp[I+1][J] +
                        dp[I][J-1] - dp[I+1][J-1];
                else
                    dp[I][J] = dp[I+1][J] + dp[I][J-1] + 1;
            }
        }
        cout << "Case " << t << ": " << dp[0][s.size()-1] << endl;
    }
}
/*******************************
* Feuzem is an unemployed computer scientist who spends his
* days working at odd-jobs. While on the job he always manages to find
* algorithmic problems within mundane aspects of everyday life.
* Today, while writing down the specials menu at the
* restaurant he's working at, he felt irritated by the lack of palindromes
* (strings which stay the same when reversed) on the menu. Feuzem is a big fan of
* palindromic problems, and started thinking about the number of ways he could
* remove letters from a particular word so that it would become a palindrome.
* Two ways that differ due to order of removing letters are
* considered the same. And it can also be the case that no letters have to be
* removed to form a palindrome.
*
* Input
* Input starts with an integer T (≤ 200),
* denoting the number of test cases.
* Each case contains a single word W (1 ≤ length(W) ≤ 60).
*
* Output
* For each case, print the case number and the total number of
* ways to remove letters from W such that it becomes a palindrome.
***/
