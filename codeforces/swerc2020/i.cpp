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
vector<int> d;
int n, m;

int bfs(int ini){
	int ans = 0;
	d.assign(n, -1);
	d[ini] = 0;
	queue<int> q; q.push(ini);
	while(!q.empty()){
		int x = q.front(); q.pop();
		for(int u:g[x])if(d[u] == -1){
			d[u] = d[x]+1;
			ans = max(ans, d[u]);
			q.push(u);
		}
	}
	return ans;
}

int main(){ _
	cin >> n >> m;
	g.resize(n);
	while(m--){
		int a, b; cin >> a >> b;
		a--, b--;
		g[a].pb(b), g[b].pb(a);
	}

	int dim = bfs(0);
	for(auto u: d){
		if(u == -1){
			cout << -1 << endl;
			exit(0);
		}
	}
	
	//dim -= 1;
	int ans = 0, log = 1;
	while(log < dim){
		log *= 2;
		ans++;
	}
	cout << ans+1 << endl;
	exit(0);
}
