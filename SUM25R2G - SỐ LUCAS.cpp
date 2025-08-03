#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll Lucas(int n) {
    if (n == 0) return 2;
    if (n == 1) return 1;
    ll prev1 = 1, prev2 = 2;
  	ll curr;

    for (int i = 2; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int main() {
    int n;
    cin >> n;
    cout << Lucas(n);
    return 0;
}