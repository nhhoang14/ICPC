#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int n; 
	cin >> n;
	int a[n];
	int tong = 0;
	int maxval = 0;
	for(int i=0; i<n; i++){
		cin >> a[i];
		tong += a[i];
		maxval = max(maxval, a[i]);
	} 
	tong -= maxval;
	if(tong > maxval) cout << "Yes";
	else cout << "No";
	return 0;
}