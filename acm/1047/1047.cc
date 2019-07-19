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

void prob_1047();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); prob_1047(); return 0;
}

void prob_1047() {
    int T; cin >> T;
    repe(t,1,T){
        int n; cin >> n;
        int dp[20][3];
        rep(i,0,n){
            rep(j,0,3) cin >> dp[i][j];
            if(i) rep(j,0,3) {
                dp[i][j] += min(dp[i-1][(j+1)%3],dp[i-1][(j+2)%3]);
            }
        }
        cout << "Case " << t << ": " << min(min(dp[n-1][0], dp[n-1][1]), dp[n-1][2]) << endl;
    }
}

/*******************************
* The people of Mohammadpur have decided to paint each of
* their houses red, green, or blue. They've also decided that no two neighboring
* houses will be painted the same color. The neighbors of house i are
* houses i-1 and i+1. The first and last houses are not neighbors.
* You will be given the information of houses. Each house will
* contain three integers "R G B" (quotes for clarity only),
* where R, G and B are the costs of painting the corresponding
* house red, green, and blue, respectively. Return the minimal total cost
* required to perform the work.
*
* Input
* Input starts with an integer T (≤ 100),
* denoting the number of test cases.
* Each case begins with a blank line and an integer n (1 ≤ n ≤ 20) denoting the number of houses.
* Each of the next n lines will contain 3 integers "R G B". These integers will lie
* in the range [1, 1000].
*
* Output
* For each case of input you have to print the case number and
* the minimal cost.
***/
