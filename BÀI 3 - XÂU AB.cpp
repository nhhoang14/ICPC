#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;

ll Ckn(ll n, ll k) {
    if (k < 0 || k > n) return 0;
    if (k > n - k) k = n - k;
    ll tmp = 1;
    for(int i = 1; i <= k; i++){
        tmp = tmp * (n - k + i) / i;
    }
    return tmp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    ll a, b, k;
    cin >> a >> b >> k;
    string res;
    while (a > 0 && b > 0) {
        ll cnt = Ckn(a + b - 1, a - 1);
        if (k <= cnt) {
            res += 'a';
            a--;
        } else {
            res += 'b';
            k -= cnt;
            b--;
        }
    }
    res += string(a, 'a') + string(b, 'b');
    cout << res;
    return 0;
}