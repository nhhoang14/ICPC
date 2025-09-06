#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            for (int k = j + 1; k < n; ++k) {
                int x = a[i], y = a[j], z = a[k];
                if (x != y && y != z && x != z &&
                    x + y > z && y + z > x && x + z > y) {
                    cnt++;
                }
            }
    cout << cnt;
}