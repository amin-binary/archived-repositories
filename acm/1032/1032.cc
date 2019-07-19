// author: amin.roosta89@gmail.com
#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <bitset>
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
using u64 = unsigned long long;
using u32 = unsigned long;

void prob_1032();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); prob_1032(); return 0;
}

u64 dp[32];
u32 slv(u32 n) {
    if(n < 2) return 0;
    u32 n2 = n, i = 0; for(;n2 >>= 1;) ++i;
    u32 res = dp[i-1];
    int m = n & ~(1 << i);
    if(m >= (1 << (i-1)))
        res += m - (1<<(i-1)) + 1;
    return res + slv(m);
}
void prob_1032() {
    rep(i,1,32) dp[i] = dp[i-1]*2 + (1 << (i-1));
    int T; cin >> T;
    repe(t,1,T){
        u32 N; cin >> N;
        cout << "Case " << t << ": " << slv(N) << endl;
    }
}

/*******************************
* A bit is a binary digit, taking a logical value of either 1
* or 0 (also referred to as "true" or "false"
* respectively). And every decimal number has a binary representation which is
* actually a series of bits. If a bit of a number is 1 and its next bit is
* also 1 then we can say that the number has a 1 adjacent bit. And
* you have to find out how many times this scenario occurs for all numbers up to N.
* 
* Examples:
*       Number        
* Binary          Adjacent Bits
*         
* 12                    1100                        1
*         
* 15                    1111                        3
*         
* 27                    11011                      2
* Input
* Input starts with an integer T (≤ 10000),
* denoting the number of test cases.
* Each case contains an integer N (0 ≤ N < 2^31).
* Output
* For each test case, print the case number and the summation
* of all adjacent bits from 0 to N.
*  
***/
