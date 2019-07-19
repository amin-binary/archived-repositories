// author: amin.roosta89@gmail.com
#include <functional>
#include <algorithm>
#include <iostream>
#include <iomanip>
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

void prob_1030();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); prob_1030(); return 0;
}

void prob_1030() {
    int T; cin >> T;
    repe(t, 1, T) {
        int N; cin >> N;
        double dp[100];
        rep(i,0,N) cin >> dp[i];
        for(int i = N - 2; i >= 0; --i) {
            int k = min(6, N-1 - i);
            double sum = 0;
            repe(j,1,k) sum += dp[i+j];
            dp[i] += sum / k;
        }
        cout << "Case " << t << ": " << setprecision(15) <<  dp[0] << endl;
    }
}

/*******************************
* You are in a cave, a long cave! The cave can be represented
* by a 1 x N grid. Each cell of the cave can contain any amount of gold.
* Initially you are in position 1. Now each turn you
* throw a perfect 6 sided dice. If you get X in the dice after
* throwing, you add X to your position and collect all the gold from the
* new position. If your new position is outside the cave, then you keep throwing
* again until you get a suitable result. When you reach the Nth
* position you stop your journey. Now you are given the information about the
* cave, you have to find out the expected number of gold you can collect
* using the given procedure.
* Input
* Input starts with an integer T (≤ 100),
* denoting the number of test cases.
* Each case contains a blank line and an integer N (1
* ≤ N ≤ 100) denoting the dimension of the cave. The next line
* contains N space separated integers. The ith integer
* of this line denotes the amount of gold you will get if you come to the ith
* cell. You may safely assume that all the given integers will be non-negative
* and no integer will be greater than 1000.
* Output
* For each case, print the case number and the expected number
* of gold you will collect. Errors less than 10-6 will be
* ignored.
*  
***/
