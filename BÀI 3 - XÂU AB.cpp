#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;

vector<vector<ll>> C(61, vector<ll>(61, -1));

ll Ckn(ll n, ll k) {
    if (k < 0 || k > n) return 0;
    if (C[n][k] != -1) return C[n][k];
    if (k == 0 || k == n) return C[n][k] = 1;
    return C[n][k] = Ckn(n - 1, k - 1) + Ckn(n - 1, k);
}

string findKthString(ll a, ll b, ll k) {
    string result;
    while (a > 0 && b > 0) {
        ll cnt = Ckn(a + b - 1, a - 1);
        if (k <= cnt) {
            result += 'a';
            a--;
        } else {
            result += 'b';
            k -= cnt;
            b--;
        }
    }
    result += string(a, 'a');
    result += string(b, 'b');
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    ll a, b, k;
    cin >> a >> b >> k;
    cout << findKthString(a, b, k);
    return 0;
}