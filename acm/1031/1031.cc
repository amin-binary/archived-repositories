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

void prob_1031();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); prob_1031(); return 0;
}

void prob_1031() {
    int T; cin >> T;
    repe(t,1,T){
        int N; cin >> N;
        int nums[101];
        rep(i,0,N) cin >> nums[i];
        int dp[100][100];
        rep(j,0,N){
            rep(i,0,N-j) {
                if(i == i+j) dp[i][i+j] = nums[i];
                else {
                    int best = -1000*1000*1000;
                    int sum = 0;
                    int sumr = 0;
                    rep(k,0,j) {
                        sum += nums[i+k];
                        best = max(best, sum - dp[i+k+1][i+j]);
                        sumr += nums[i+j-k];
                        best = max(best, sumr - dp[i][i+j-k-1]);
                    }
                    dp[i][i+j] = max(best, sum + nums[i+j]);
                }
            }
        }
        cout << "Case " << t << ": " << dp[0][N-1] << endl;
    }
}

/*******************************
* You are playing a two player game. Initially there are n
* integer numbers in an array and player A and B get chance to take
* them alternatively. Each player can take one or more numbers from the left or
* right end of the array but cannot take from both ends at a time. He can take as
* many consecutive numbers as he wants during his time. The game ends when all
* numbers are taken from the array by the players. The point of each player is
* calculated by the summation of the numbers, which he has taken. Each player
* tries to achieve more points from other. If both players play optimally and
* player A starts the game then how much more point can player A
* get than player B?
* Input
* Input starts with an integer T (≤ 100),
* denoting the number of test cases.
* Each case contains a blank line and an integer N (1
* ≤ N ≤ 100) denoting the size of the array. The next line
* contains N space separated integers. You may assume that no number will
* contain more than 4 digits.
* Output
* For each test case, print the case number and the maximum
* difference that the first player obtained after playing this game optimally.
*  
***/
