#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.rbegin(), a.rend());
    string res = "";
    vector<string> path;
    for (int i = 0; i < 3; i++) path.push_back(to_string(a[i]));
    do{
        string cur = path[0] + path[1] + path[2];
        if (cur > res) res = cur;
    } while (next_permutation(path.begin(), path.end()));
    cout << res << endl;
    return 0;
}
