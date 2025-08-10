#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    ll k;
    cin >> s >> k;
    sort(s.begin(), s.end());
    for (ll i = 1; i < k; i++) {
        next_permutation(s.begin(), s.end());
    }

    cout << s;
    return 0;
}
