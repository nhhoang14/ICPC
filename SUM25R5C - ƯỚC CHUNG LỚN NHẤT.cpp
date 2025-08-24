#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

int main() {
    long long n, p;
    cin >> n >> p;
    map<long long, long long> ptich;
    for (long long i = 2; i * i <= p; i++) {
        if (p % i == 0) {
            long long solan = 0;
            while (p % i == 0) {
                solan++;
                p /= i;
            }
            ptich[i] = solan;
        }
    }
    if (p > 1)
        ptich[p] = 1;
    long long ucln = 1;
    for (pair<long long, long long> x : ptich) {
        ucln *= (long long)pow(x.first, (x.second) / n);
    }
    cout << ucln;
    return 0;
}
