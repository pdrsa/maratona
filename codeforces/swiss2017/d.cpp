//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
// #define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> g;
vector<int> d;

void bfs(int ini){
	d[ini] = 0;
	queue<int> q; q.push(ini);
	while(!q.empty()){
		int x = q.front(); q.pop();
		for(int u: g[x]) if(d[u] == -1){
			d[u] = d[x] + 1;
			q.push(u);
		}
	}
}

int32_t main(){ _
	int n, m, k; cin >> n >> m >> k;
	g.resize(n);
	while(m--){
		int a, b; cin >> a >> b;
		a--, b--;
		g[a].pb(b), g[b].pb(a);
	}

	int maxi = -INF;
	for(int i = 0; i < n; i++){
		d.assign(n, -1);
		bfs(i);
		for(int j = 0; j < n; j++) maxi = max(maxi, d[j]);
	}
	
	if(maxi > n-k) cout << 0 << endl;
	else{
		cout << n << endl;
		for(int i = 1; i <= n; i++) cout << i << " ";
		cout << endl;
	}
	exit(0);
}
