#include<iostream>
#include<algorithm>
using namespace std;

using ll = long long;
int main() {
    ll Y, B;
    cin >> Y >> B;
    ll y, g, b;
    cin >> y >> g >> b;
    cout <<  max(3*b + g - B, 0ll) + max(2*y + g - Y, 0ll) << endl;
    return 0;
}
