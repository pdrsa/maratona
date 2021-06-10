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

vector<vector<ii>> g;
vector<int> d;

int maxi = -INF;
int k;

void bfs(int s){
	queue<int> q;
	q.push(s);
	d[s] = 0;
	while(!q.empty()){
		int x = q.front(); q.pop();
		if(d[x] >= k) continue;
		for(ii now: g[x]){
			int u   = now.f;
			int dis = now.s;
			maxi = max(dis, maxi);
			if(d[u] == -1){
				d[u] = d[x] + 1;
				q.push(u);
			}
		}
	}
}

int main(){ _
	// #warning FILE IN
	freopen("path.in", "r", stdin);
	int tt; cin >> tt;
	while(tt--){
		maxi = -INF;
		int n, m, u, l;
		cin >> n >> m >> u >> l >> k;
		g = vector<vector<ii>> (n);
		d = vector<int> (n, -1);
		for(int i = 0; i < m; i++){
			int a, b, w; cin >> a >> b >> w;
			a--, b--;
			g[a].pb({b, w}), g[b].pb({a, w});
		}
		bfs(u-1);
		cout << maxi << endl;
	}
	exit(0);
}
