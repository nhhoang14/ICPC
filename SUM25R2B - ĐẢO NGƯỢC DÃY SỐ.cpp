#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int main(){
	int n; 
	cin >> n;
	deque<int> dq;
	for(int i = n; i >= 1; i--){
		int temp; cin >> temp;
		if(i % 2 == 0) dq.push_back(temp);
		else dq.push_front(temp);
	}
	while(!dq.empty()){
		cout << dq.front() << " ";
		dq.pop_front();
	}
	return 0;
}