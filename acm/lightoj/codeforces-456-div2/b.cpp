#include<iostream>
#include<algorithm>
using namespace std;

using ul = long long;
int main() {
    ul k, n;
    cin >> n >> k;

    ul res = 0;
    while(n) {
        n /= 2;
        res *= 2;
        if(k) {
            res += 1;
            --k;
        }
        cout << res << endl;
    };

    cout << res << endl;

    return 0;
}
