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

#define rep(i, f, t) for(int i = f; i < t; ++i)
#define all(v)       v.begin(), v.end()

using namespace std;
using ii = pair<int, int>;
using vi = vector<int>;

void prob_1018();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); prob_1018(); return 0;
}

struct point {
    int x, y;
};
const int N = 16;

int dp[1 << N];
int bst[N][N] = { };

int n;
int go(int mask) {
    if(dp[mask] != -1) {
        return dp[mask];
    }
    if((mask & (mask-1)) == 0) return dp[mask] = 1;

    int ret = N+1;
    rep(i, 0, n) if(mask & (1<<i)) {
        rep(j, i+1, n) if((mask & (1<<j))) {
            ret = min(ret, 1 + go(mask & ~bst[i][j]));
        }
        break;
    }
    dp[mask] = ret;
    return dp[mask];
}

void prob_1018() {
    int T; cin >> T;
    for(int t = 1; T--; ++t) {
        cin >> n;
        point pts[N];
        for(int i = 0; i < n; ++i) cin >> pts[i].x >> pts[i].y;

        rep(i,0,n) {
            bst[i][i] = (1<<i);
            rep(j,i+1,n) {
                bst[i][j] = 0;
                rep(k,0,n) if((pts[i].x - pts[j].x)*(pts[j].y - pts[k].y) == (pts[j].x - pts[k].x)*(pts[i].y - pts[j].y))
                    bst[i][j] |= (1 << k);
                bst[j][i] = bst[i][j];
            }
        }
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        cout << "Case " << t << ": " << go((1<<n)-1) << endl;
    }
}
