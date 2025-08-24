#include <bits/stdc++.h>
using namespace std;

int kcc2(int x1, int y1, int x2, int y2) {
    int dx = x1 - x2;
    int dy = y1 - y2;
    return dx*dx + dy*dy;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> a(n+1);
    for (int i=1; i<=n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    vector<vector<pair<int,int>>> d(n+1, vector<pair<int,int>>(n+1, {-1,0}));
    for (int i=1; i<n; i++) {
        for (int j=i+1; j<=n; j++) {
            int dist = kcc2(a[i].first,a[i].second,a[j].first,a[j].second);
            d[i][j] = {dist, j};
            d[j][i] = {dist, i};
            if(d[i][0].first < dist) {
                d[i][0] = {dist,j};
            } else if(d[i][0].first == dist) {
                d[i][0].second = min(d[i][0].second, j);
            }
            if(d[j][0].first < dist) {
                d[j][0] = {dist,i};
            } else if(d[j][0].first == dist) {
                d[j][0].second = min(d[j][0].second, i);
            }
        }
    }
    for (int i=1; i<=n; i++) {
        cout << d[i][0].second << endl;
    }
    return 0;
}
