#include<iostream>
#include<algorithm>

using namespace std;

int k, s, cnt = 0;

void Backtracking(int i, int sum) {
    if (sum > s) return;
    if (i == 2) {
        if (s - sum <= k) cnt++;
        return;
    }
    for (int j = 0; j <= k; j++) {
        Backtracking(i + 1, sum + j);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> k >> s;
    Backtracking(0, 0);
    cout << cnt;
    return 0;
}