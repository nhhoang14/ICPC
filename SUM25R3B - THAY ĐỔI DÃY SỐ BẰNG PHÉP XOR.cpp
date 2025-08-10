#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    if (n > 130) {
        cout << 1 << '\n';
        return 0;
    }
    vector<ll> pref(n + 1, 0);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] ^ a[i];

    const int INF = 1e9;
    int ans = INF;
    for (int l = 0; l < n; l++){
        for (int r = l + 1; r < n; r++){
            for (int k = l; k < r; k++){
                ll left = pref[k + 1] ^ pref[l];
                ll right = pref[r + 1] ^ pref[k + 1];
                if (left > right){
                    ans = min(ans, r - l - 1);
                }
            }
        }
    }
    if (ans == INF){
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
    return 0;
}
