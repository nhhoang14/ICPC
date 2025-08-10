#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll x, y;
    cin >> x >> y;
    ll res = abs(x - y);
    if(res <= 1) cout << "Bob";
    else cout << "Alice";
    return 0;
}
