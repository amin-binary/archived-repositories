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

void prob_1036();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); prob_1036(); return 0;
}

void prob_1036() {
    int T; cin >> T;
    repe(t,1,T){
        int m,n; cin >> m >> n;
        int dp[500][500] = { };
        int ur[500][500];
        int ra[500][500];
        rep(i,0,m) rep(j,0,n) {
            cin >> ur[i][j];
            if(j) ur[i][j] += ur[i][j-1];
        }
        rep(i,0,m) rep(j,0,n) {
            cin >> ra[i][j];
            if(i) ra[i][j] += ra[i-1][j];
        }
        rep(i,0,m) rep(j,0,n) {
            dp[i][j] = max(
                    ur[i][j] + (i ? dp[i-1][j] : 0),
                    ra[i][j] + (j ? dp[i][j-1] : 0)
            );
        }
        cout << "Case " << t << ": " << dp[m-1][n-1] << endl;
    }
}

/*******************************
* Its year 2200, planet Earth is out of resources and people
* are relying on the resources from other planets. There are several Refining
* Companies who collect these resources from other planets and bring them back to
* Earth. The task may sound simple, but in reality it's a challenging job. The
* resources are scattered and after collecting them, they have to be taken to a
* place where they can be refined. Since some minerals are extremely dangerous,
* the whole process should be done very carefully. A single tiny mistake can
* cause a massive explosion resulting in a huge loss.
* You work in such a company who collects Uranium and Radium
* from planet Krypton. These minerals are used for generating powers. For
* simplicity you have divided planet Krypton into cells that form a matrix of m
* rows and n columns, where the rows go from east to west and the columns go from
* north to south. Your advanced mine detector has detected the approximate amount
* of Radium and Uranium in each cell. Your company has built two refining
* factories, one in West and the other in North. The factory in North is used to
* refine Radium and the factory in West is used to refine Uranium. Your task is
* to design the conveyor belt system that will allow them to mine the largest amount
* of minerals. 
* There are two types of conveyor belts: the first moves
* minerals from east to west, the second moves minerals from south to north. In
* each cell you can build either type of conveyor belt, but you cannot build both
* of them in the same cell. If two conveyor belts of the same type are next to
* each other, then they can be connected. For example, the Radium mined at a cell
* can be transported to the Radium refinement factory via a series of south-north
* conveyor belts.
* The minerals are very unstable, thus they have to be brought
* to the factories on a straight path without any turns. This means that if there
* is a south-north conveyor belt in a cell, but the cell north of it contains an
* east-west conveyor belt, then any mineral transported on the south-north
* conveyor belt will be lost. The minerals mined in a particular cell have to be
* put on a conveyor belt immediately; in the same cell (thus they cannot start
* the transportation in an adjacent cell). Furthermore, any Radium transported to
* the Uranium refinement factory will be lost, and vice versa.
* 
* Your program has to design a conveyor belt system that
* maximizes the total amount of minerals mined, i.e., the sum of the amount of
* Radium transported to the Radium refinery and the amount of Uranium to the
* Uranium refinery.
* Input
* Input starts with an integer T (≤ 10),
* denoting the number of test cases.
* Each case begins with a blank line and two integers: m
* - the number of rows, and n - the number columns (1 ≤ m, n
* ≤ 500). The next m lines describe the amount of Uranium that
* can be found in the cells. Each of these m lines contains n
* integers. The first line corresponds to the northernmost row; the first integer
* of each line corresponds to the westernmost cell of the row. The integers are
* between 0 and 1000. The next m lines describe in a similar
* fashion the amount of Radium found in the cells. Data set is huge, so use
* faster i/o methods.
* Output
* For each case of input you have to print the case number and the
* maximum amount of minerals you can collect.
* Note
* Dataset is huge. Use faster I/O methods.
***/
