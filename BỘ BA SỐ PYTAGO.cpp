#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
using namespace std;
typedef long long ll;

bool scp(ll n) {
    ll r = sqrt(n);
    return r * r == n;
}

int main(){
	ll n; 
    cin >> n;
	for(ll i = 1; i <= 100000; i++){
		ll x = 2 * n * n - i * i;
		ll sqx = sqrt(x);
		if(scp(x) && sqx != i && sqx != n && sqx <= 100000){
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}