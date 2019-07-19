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
#define repe(i, f, t) for(int i = f; i <= t; ++i)
#define all(v)       v.begin(), v.end()

using namespace std;
using ii = pair<int, int>;
using vi = vector<int>;

void prob_1004();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); prob_1004(); return 0;
}

void prob_1004() {
  int T; cin >> T;
  repe(t,1, T) {
    int n; cin >> n;
    int dp[203][103] = { };
    rep(i, 1, 2*n) {
      int till = i <= n ? i : 2*n - i;
      repe(j, 1, till) {
        cin >> dp[i][j];
        dp[i][j] += std::max(dp[i-1][j], dp[i-1][i <= n ? j-1 : j+1]);
      }
    }
    cout << "Case " << t << ": " << dp[2*n-1][1] << endl;
  }
}
