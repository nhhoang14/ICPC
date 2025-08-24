#include <iostream>
#include <vector>
using namespace std;

int m, n, r, c, need;
vector<vector<int>> a;

bool check(int x) {
    vector<vector<int>> b(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            b[i][j] = (a[i][j] <= x ? 1 : 0);

    vector<vector<int>> s(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            s[i][j] = b[i-1][j-1] + s[i-1][j] + s[i][j-1] - s[i-1][j-1];

    for (int i = r; i <= m; i++)
        for (int j = c; j <= n; j++) {
            int cnt = s[i][j] - s[i-r][j] - s[i][j-c] + s[i-r][j-c];
            if (cnt >= need){
                return true;
            }
        }
    return false;
}

int main() {
    cin >> m >> n >> r >> c;
    need = (r * c) / 2 + 1;
    a.assign(m, vector<int>(n));
    int lo = 0, hi = 1e9, ans = 0;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
