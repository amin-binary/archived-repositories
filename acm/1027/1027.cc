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

void prob_1027();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); prob_1027(); return 0;
}

void prob_1027() {
    int T; cin >> T;
    repe(t,1,T){
        int total = 0;
        int pc = 0; // positive count
        int n; cin >> n;
        rep(i,0,n) {
            int tmp; cin >> tmp;
            pc += (tmp > 0);
            total += abs(tmp);
        }
        int pcc = pc;
        repe(i,2,pcc) while(pc%i == 0 && total%i == 0) {
            pc /= i;
            total /= i;
        }
        cout << "Case " << t << ": ";
        if(pc) cout << total << "/" <<  pc << endl;
        else cout << "inf" << endl;
    }
}

/*******************************
* You are in a maze; seeing n doors in front of you in
* beginning. You can choose any door you like. The probability for choosing a
* door is equal for all doors.
* If you choose the ith door, it can either
* take you back to the same position where you begun in xi
* minutes, or can take you out of the maze after xi minutes. If
* you come back to the same position, you can't remember anything. So, every time
* you come to the beginning position, you have no past experience.
* Now you want to find the expected time to get out of the
* maze.
* Input
* Input starts with an integer T (≤ 100),
* denoting the number of test cases.
* Each case contains a blank line and an integer n (1
* ≤ n ≤ 100) denoting the number of doors. The next line contains
* n space separated integers. If the ith integer (xi)
* is positive, you can assume that the ith door will take you
* out of maze after xi minutes. If it's negative, then the ith
* door will take you back to the beginning position after abs(xi)
* minutes. You can safely assume that 1 ≤ abs(xi) ≤ 10000.
* Output
* For each case, print the case number and the expected time
* to get out of the maze. If it's impossible to get out of the maze, print 'inf'.
* Print the result in p/q format. Where p is the numerator of the
* result and q is the denominator of the result and they are relatively
* prime. See the samples for details.
*  
***/
