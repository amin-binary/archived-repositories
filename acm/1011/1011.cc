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

void prob_1011();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); prob_1011(); return 0;
}

const int N = 16;
int dp[1 << N];
int seen[1 << N];
int cost[N][N];

void prob_1011() {
  int T; cin >> T;
  rep(t, 0, T) {
    int n; cin >> n;
    rep(i, 0, 1 << n) {
      dp[i] = seen[i] = 0;
    }
    rep(i, 0, n)
      rep(j, 0, n)
        cin >> cost[i][j];
    rep(i, 0, 1 << n) {
        rep(ii, 0, n)
            rep(jj, 0, n)
              if(!(i&(1<<ii)) && !(seen[i]&(1 <<jj))) {
                int s = dp[i] + cost[ii][jj];
                if(s > dp[i|(1<<ii)]) {
                  dp[i|(1<<ii)] = s;
                  seen[i|(1<<ii)] = seen[i] | (1 << jj);
                }
              }
    }
    cout << "Case " << (t+1) << ": " << dp[(1<<n)-1] << endl;
  }
} 