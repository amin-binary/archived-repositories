
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
using ii = pair<int, int>;
using vi = vector<int>;
 
void prob_1017();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); prob_1017(); return 0;
}
 
struct point {
    int y;
    int cnt;
};
 
bool operator<(const point& a, const point& b) {
    return a.y < b.y;
};
 
void prob_1017() {
    int T; cin >> T;
    for(int t = 1; T--; ++t) {
        int N, w, k; cin >> N >> w >> k;
        vector<point> pts;
        pts.reserve(N);
        rep(i, 0, N) {
            int x,y; cin >> x >> y;
            bool found = false;
            for(auto& pt : pts)
                if(pt.y == y) {
                    pt.cnt++;
                    found = true;
                    break;
                }
            if(!found) pts.push_back({y, 1});
        }
        sort(all(pts));
        /* for(auto& p : pts) cout << "pt:" << p.y << ", " << p.cnt << endl; */
        int dp[101][101] = { };
        rep(i, 0, pts.size()) {
            int ii = i;
            int best = 0;
            for(; ii >= 0 && pts[i].y - pts[ii].y <= w; ) {
                best += pts[ii].cnt;
                /* dp[i][1] += pts[ii].cnt; */
                --ii;
            }
            if(ii >= 0)
                rep(j, 1, k+1)  dp[i][j] = max(dp[i-1][j], dp[ii][j-1] + best);
            else
                rep(j, 1, k+1)
                    dp[i][j] = best;
        }
 
        cout << "Case " << t << ": " << dp[pts.size()-1][k] << endl;
    }
}
