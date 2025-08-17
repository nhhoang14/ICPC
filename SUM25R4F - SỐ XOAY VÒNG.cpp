#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, res = 0;
    cin >> n;
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    res = sum + sum*10 + sum*100;
    cout << res << endl;
    return 0;
}