#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<char> vs;

signed main(){
	ios_base::sync_with_stdio(0); 
    cin.tie(NULL); 
    cout.tie(NULL);
	cin >> n >> m;
	
	adj.assign(n+1, {});
	vs.assign(n+1, 0);
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	int best = 1;
	for(int i = 1; i <= n; i++){
		if(vs[i]) continue;
		int cnt = 0;
		queue<int> q;
		q.push(i);
		vs[i] = 1;
		while(!q.empty()){
			int u = q.front(); q.pop();
			cnt++;
			for(int v : adj[u]){
				if(!vs[v]){
					vs[v] = 1;
					q.push(v);
				}
			}
		}
		best = max(best, cnt);
	}
	
	cout << best << endl;
	return 0;
}