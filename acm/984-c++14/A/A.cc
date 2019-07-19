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

int arr[1001];
int main()  {
    int n; cin >> n;
    rep(i,0,n) cin >> arr[i];
    std::sort(arr, arr+n);
    cout << arr[(n-1)/2] << endl;
    return 0;
};
