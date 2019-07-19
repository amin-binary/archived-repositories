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
 
void prob_1013();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); prob_1013(); return 0;
}
using ull = unsigned long long;
const int MAX = 35;
#define min_(a,b,c) ((a) < (b) && (a) < (c) ? (a) : (b) < (c) ? (b) : (c))
 
/**
 * abc
 * dc
 *
 * a,d => 2
 * ab,d => a,d + ab,- => 2 + 1 => 3
 * a,dc => a,d + 0,dc => 2 + 1 => 3
 * ab,dc => ab,d + a,dc => 3 + 3 => 6
 * abc,d => abc,- + ab,d => 1 + 3 => 4
 * abc,dc => ab,dc + abc,d
 *
 * usa
 * ussr
 *
 * u,u => 1
 * us,u => u,u => 1
 * u,us => u,u => 1
 * us,us => 1
 * usa,us => 1
 * us,uss => 1
 * usa,uss => 2
 * usa,ussr => 2 + 2 => 4
 */
 
void prob_1013() {
    int T; cin >> T;
    rep(t, 0, T) {
        string a,b; cin >> a >> b;
        int al = a.length(), bl = b.length();
        int dp[MAX][MAX] = { };
        ull cnt[MAX][MAX] = { };
        rep(i, 0, al+1) {
            rep(j, 0, bl+1) {
                if(i == 0) dp[i][j] = j;
                else if(j == 0) dp[i][j] = i;
                else dp[i][j] = min_(dp[i-1][j-1] + 1 + (a[i-1] != b[j-1]), dp[i-1][j] + 1, dp[i][j-1] + 1);
 
                if(i == 0) cnt[i][j] = 1;
                else if(j == 0) cnt[i][j] = 1;
                else cnt[i][j] =
                        a[i-1] == b[j-1] ?  cnt[i-1][j-1] :
                        dp[i-1][j] < dp[i][j-1] ? cnt[i-1][j] :
                        dp[i][j-1] < dp[i-1][j] ? cnt[i][j-1] :
                        cnt[i][j-1] + cnt[i-1][j];
            }
        }
        cout << "Case " << (t+1) << ": " << dp[al][bl] << ' ' << cnt[al][bl] << endl;
    }
}
