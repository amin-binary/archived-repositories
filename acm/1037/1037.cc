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

void prob_1037();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); prob_1037(); return 0;
}

void prob_1037() {
    int T; cin >> T;
    repe(t,1,T){
        int N; cin >> N;
        int h[16]; rep(i,0,N) cin >> h[i];
        char dmg[20][20];
        rep(i,0,N) {
            cin >> dmg[i];
            rep(j,0,N) dmg[i][j] -= '0';
        }
        int dp[1 << 15];
        dp[0] = 0;
        rep(i,1,1<<N) {
            dp[i] = 1000*1000;
            rep(k,0,N) if(i&(1<<k)) {
                int ii = i & ~(1<<k);
                int bst = 1;
                rep(p,0,N) if(ii & (1<<p))
                    bst = max(bst, (int)dmg[p][k]);
                dp[i] = min(dp[ii] + h[k]/bst + (h[k]%bst > 0), dp[i]);
            }
        }
        cout << "Case " << t << ": " << dp[(1<<N)-1] << endl;
    }
}

/*******************************
* Agent 47 is in a dangerous Mission "Black Monster Defeat - 15".
* It is a secret mission and so 47 has a limited
* supply of weapons. As a matter of fact he has only one weapon the old weak
* "KM .45 Tactical (USP)". The mission sounds simple - "he
* will encounter at most 15 Targets and he has to kill them all". The main
* difficulty is the weapon. After huge calculations, he found a way out. That is
* after defeating a target, he can use target's weapon to kill other targets. So
* there must be an order of killing the targets so that the total number of
* weapon shots is minimized. As a personal programmer of Agent 47 you have to
* calculate the least number of shots that need to be fired to kill all the
* targets.
* 
* Agent 47
* Now you are given a list indicating how much damage each
* weapon does to each target per shot, and you know how much health each target
* has. When a target's health is reduced to 0 or less, he is killed. 47
* start off only with the KM .45 Tactical (USP), which does damage 1
* per shot to any target. The list is represented as a 2D matrix with the ith
* element containing N single digit numbers ('0'-'9'), denoting the
* damage done to targets 0, 1, 2, ..., N-1 by the weapon obtained from
* target i, and the health is represented as a series of N
* integers, with the ith element representing the amount of
* health that target has.
* Given the list representing all the weapon damages, and the
* health each target has, you should find the least number of shots he needs to
* fire to kill all of the targets.
* Input
* Input starts with an integer T (≤ 40),
* denoting the number of test cases.
* Each case begins with a blank line and an integer N (1 ≤ N ≤ 15).
* The next line contains N space separated
* integers between 1 and 106 denoting the health of the targets 0, 1, 2, ..., N-1. Each of the
* next N lines contains N digits. The jth digit
* of the ith line denotes the damage done to target j,
* if you use the weapon of target i in each shot.
* Output
* For each case of input you have to print the case number and
* the least number of shots that need to be fired to kill all of the targets.
*  
***/
