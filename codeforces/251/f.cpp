//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> iill;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
vector<vector<int>> g;
vector<bool> vis;
vector<int> c;

void dfs(int x){
	vis[x] = true;
	for(int i: g[x]) if(!vis[i]) dfs(i);
}

void bfs(int z){
	queue<int> q; q.push(z);
	while(!q.empty()){
		int x = q.front(); q.pop();
		c[x] = 1;
		for(int i: g[x]){
			c[i] = 0;
			for(int j: g[i]){
				if(i == x) continue;

				if(c[j] == -1) q.push(j);
			}
		}
	}
}

int main(){ _
	int tt; cin >> tt;
	while(tt--){
		int n, m; cin >> n >> m;
		g = vector<vector<int>>(n);
		while(m--){
			int a, b; cin >> a >> b;
			a--, b--;
			g[a].pb(b), g[b].pb(a);
		}

		vis = vector<bool> (n);
		dfs(0);
		bool ok = true;
		for(auto u: vis) if(!u) ok = false;
		
		if(!ok){
			cout << "NO" << endl;
			continue;
		}

		c = vector<int> (n, -1);
		bfs(0);
		cout << "YES" << endl;
		int ans = 0;
		for(int i = 0; i < n; i++) if(c[i] == 1) ans++;
		cout << ans << endl;
		for(int i = 0; i < n; i++) if(c[i] != 0) cout << i+1 << " ";
		cout << endl;
	}
	exit(0);
}
