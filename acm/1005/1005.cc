// author: amin.roosta89@gmail.com
#include <functional>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <cmath>
#include <list>
#include <map>
#include <set>

#define rep(i, f, t) for(int i = f; i < t; ++i)
#define all(v)       v.begin(), v.end()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

void prob_1005();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); prob_1005(); return 0;
}

/**
 * s(n,k) = (n^2*(n-1)^2* ... (n-k)^2)/k!
 * s(n+1, k+1) = s(n,k) * (n+1)^2/(k+1)
*/


void prob_1005() {
  int T; cin >> T;
  ll dp[31][901] = {};
  dp[0][0] = 1;
  rep(i, 1, 31) {
    dp[i][0] = 1;
    rep(j, 1, i+1) {
      dp[i][j] = dp[i-1][j-1] * i * i / j;
    }
  }


  rep(t, 0, T) {
    int n, k; cin >> n >> k;
    cout << "Case " << (t+1) << ": " << dp[n][k] << endl;
  }
}
