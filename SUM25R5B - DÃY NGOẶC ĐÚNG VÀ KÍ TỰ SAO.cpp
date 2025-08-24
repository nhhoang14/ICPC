#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
	int t; cin>>t;
	while(t--){
		string s; cin>>s;
		vector<char> stk;
		for(char x: s){
			if(!stk.empty()){
				if(stk.back()=='('&&x==')') stk.pop_back();
				else stk.push_back(x);
			}
			else{
				stk.push_back(x);
			}
		}
		int deml =0, demr = 0;
		int l=0, r=stk.size()-1;
		while(stk[l]!='*'){
			if(stk[l]=='(') deml++;
			l++;
		}
		while(stk[r]!='*'){
			if(stk[r]==')') demr++;
			r--;
		}
		cout<<min(deml,demr);
		cout<<endl;
	}
	return 0;
}