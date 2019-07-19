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
using ll = unsigned long long;

void prob_1021();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); prob_1021(); return 0;
}

ll dp[1 << 16][20] = { };
void prob_1021() {
    int map[128];
    repe(ch, '0', '9') map[ch] = ch - '0';
    repe(ch, 'A', 'F') map[ch] = ch - 'A' + 10;
    int T; cin >> T;
    repe(t, 1, T) {
        int b, k; cin >> b >> k;
        string s; cin >> s;
        int n = s.length();
        int num[16];
        rep(i, 0, n) num[i] = map[int(s[i])];

        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        rep(i, 0, 1 << n) {
            rep(j, 0, n) if(!(i & (1 << j))) {
                rep(kk, 0, k) {
                    int rem = (kk * b + num[j])%k;
                    dp[i | (1<<j)][rem] += dp[i][kk];
                }
            }
        }
        cout << "Case " << t << ": " << dp[(1<<n)-1][0] << endl;
    }
}

/*******************************
* As you know that sometimes base conversion is a painful
* task. But still there are interesting facts in bases.
* For convenience let's assume that we are dealing with the
* bases from 2 to 16. The valid symbols are 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A,
* B, C, D, E and F. And you can assume that all the numbers given in this
* problem are valid. For example 67AB is not a valid number of base 11,
* since the allowed digits for base 11 are 0 to A.
* Now in this problem you are given a base, an integer K
* and a valid number in the base which contains distinct digits. You have to find
* the number of permutations of the given number which are divisible by K.
* K is given in decimal.
* For this problem, you can assume that numbers with leading
* zeroes are allowed. So, 096 is a valid integer.
*
* Input
* Input starts with an integer T (≤ 100),
* denoting the number of test cases.
* Each case starts with a blank line. After that there will be
* two integers, base (2 ≤ base ≤ 16) and K (1 ≤ K ≤ 20).
* The next line contains a valid integer in that base
* which contains distinct digits, that means in that number no digit occurs more
* than once.
*
* Output
* For each case, print the case number and the desired result.
***/
