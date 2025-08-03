#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

ll Ckn(int n, int k) {
    if (k < 0 || k > n) return 0;
    ll res = 1;
    for (int i = 1; i <= k; i++) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

char charAt(int a, int b, long long k, int idx) {
    for (int i = 0; i <= a + b; ++i) {
        if (a == 0) return 'b';
        if (b == 0) return 'a';
        long long cnt = Ckn(a + b - 1, a - 1);
        if (k <= cnt) {
            if (i == idx) return 'a';
            --a;
        } else {
            k -= cnt;
            if (i == idx) return 'b';
            --b;
        }
    }
    return '?'; // không xảy ra
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll a, b, k;
    cin >> a >> b >> k;

    string res = "";
    while(a > 0 && b > 0) {
        ll cnt = Ckn(a + b - 1, b - 1);
        cout << "Ckn(" << a + b - 1 << ", " << b - 1 << ") = " << cnt << endl;
        if (cnt >= k) {
            res += 'a';
            a--;
        } else {
            k -= cnt;
            res += 'b';
            b--;
        }
    }
    res += string(a, 'a') + string(b, 'b');
    cout << res ;
    return 0;
}