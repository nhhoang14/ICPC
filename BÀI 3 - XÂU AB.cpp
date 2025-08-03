#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a, b, k;
    cin >> a >> b >> k;
    vector<char> res (a, 'a');
    while(b--) {
        res.push_back('b');
    }
    do{
        if(k == 1){ 
            for(auto x : res) {
                cout << x;
            }
        } else if (k > 1) continue;
        else break;
    } while(next_permutation(res.begin(), res.end()) && k--);
    return 0;
}