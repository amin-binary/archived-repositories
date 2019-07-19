// author: amin.roosta89@gmail.com
#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <iomanip>
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

void prob_1038();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); prob_1038(); return 0;
}

const int MAX = 1000*100 + 1;
double dp[MAX];
int dpc[MAX];
void prob_1038() {
    rep(i,2,MAX) {
        ++dpc[i];
        dp[i] = (dp[i] + dpc[i] + 1)/dpc[i];
        for(int j = i * 2; j < MAX; j += i) {
            ++dpc[j];
            dp[j] += dp[i];
        }
    }
    int T; cin >> T;
    repe(t,1,T) {
        int n; cin >> n;
        cout << "Case " << t << ": " << setprecision(15) << dp[n] << endl;
    }
}

/*******************************
* Rimi learned a new thing about integers, which is - any
* positive integer greater than 1 can be divided by its divisors. So, he
* is now playing with this property. He selects a number N. And he calls
* this D.
* In each turn he randomly chooses a divisor of D (1
* to D). Then he divides D by the number to obtain new D. He
* repeats this procedure until D becomes 1. What is the expected
* number of moves required for N to become 1.
* Input
* Input starts with an integer T (≤ 10000),
* denoting the number of test cases.
* Each case begins with an integer N (1 ≤ N ≤ 10^5).
* Output
* For each case of input you have to print the case number and the
* expected value. Errors less than 10-6 will be ignored.
*  
***/
