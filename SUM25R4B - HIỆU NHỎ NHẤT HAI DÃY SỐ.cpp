#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    int i_a = 0, i_b = 0;
    int hieu = abs(a[i_a] - b[i_b]);
    while (i_a < n && i_b < m){
        hieu = min(hieu, abs(a[i_a] - b[i_b]));
        if (a[i_a] < b[i_b]){
            i_a++;
        } else if (a[i_a] > b[i_b]) {
            i_b++;
        } else {
            cout << 0;
            return 0;
        }
    }
    cout << hieu;
    return 0;
}