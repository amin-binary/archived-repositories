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

void prob_1050();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); prob_1050(); return 0;
}

/**
 * (n,0) => 0
 * (0,n) => 1
 * (1,2) => (0,1)*1/3 + (1,0)*2/3  = 1/3
 * (2,3) => (1,2)*2/5 + (2,1)*3/5 = 2/15
 * (2,1) => (1,0)*2/3 + (2,-1)*1/3 = 0
 * (2,5) => (1,4)*2/7 + (2,3)*5/7 => 7/15*2/7 + 2/15*5/7 => 2/15 + 2/21 = 0.2285714286
 * (1,4) => (0,3)*1/5 + (1,2)*4/5 => 1/5 + 1/3*4/5 => 7/15
 */
void prob_1050() {
    const int MAX = 1000;
    double dp[MAX][MAX] = {};
    rep(r,0,MAX) rep(b,0,MAX) if((r+b)%2) {
        if(!r) dp[r][b] = 1;
        else if(!b) dp[r][b] = 0;
        else {
            dp[r][b] = dp[r-1][b-1]*r + (b >= 2 ? dp[r][b-2] : 0)*b;
            dp[r][b] /= (r+b);
        }
        /* cout << "dp["<<r<<"]["<<b<<"] = " << dp[r][b] << endl; */
    }
    int T; cin>>T;
    repe(t,1,T){
        int r,b; cin >>r>>b;
        cout << "Case " << t << ": " << setprecision(12) <<  dp[r][b] << endl;
    }
}

/*******************************
* Your friend Jim has challenged you to a game. He has a bag
* containing red and blue marbles. There will be an odd number of marbles in the
* bag, and you go first. On your turn, you reach into the bag and remove a random
* marble from the bag; each marble may be selected with equal probability. After
* your turn is over, Jim will reach into the bag and remove a blue marble; if
* there is no blue marble for Jim to remove, then he wins. If the final marble
* removed from the bag is blue (by you or Jim), you will win. Otherwise, Jim
* wins.
* Given the number of red and blue marbles in the bag,
* determine the probability that you win the game.
*
* Input
* Input starts with an integer T (≤ 10000),
* denoting the number of test cases.
* Each case begins with two integers R and B
* denoting the number of red and blue marbles respectively.
* You can assume that 0 ≤ R, B ≤ 500 and R+B is odd.
*
* Output
* For each case of input you have to print the case number and
* your winning probability. Errors less than 10-6 will be ignored.
***/
