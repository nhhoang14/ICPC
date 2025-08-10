#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, w;
    cin >> n >> w;
    int a[n];
    for (auto &x : a) cin >> x;
    sort(a, a + n);
    int cnt = 0;
    int l = 0, r = n - 1;
    while (l < r){
        if (a[l] + a[r] > w){
            cnt++;
            r--;
        } else {
            cnt++;
            l++;
            r--;
        }
    }
    if (l == r) cnt++;
    cout << cnt;
}