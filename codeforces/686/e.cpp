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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll n, ans;
vector<vector<int>> g;
vector<bool> d;
vector<int> dist;

void bfs(int x) {
	queue<int> q;
	ans = 0;
	d = vector<bool>(n);
	dist = vector<int>(n);
	q.push(x);
	dist[x] = 0;

	while(!q.empty()) {
		int s = q.front(); q.pop();
		d[s] = true;
		for(auto u : g[s]) if(!d[u]){
			dist[u] = dist[s]+1;
			q.push(u);
			ans += dist[u] * g[s].size()-1;
		}
	}
}

int main(){ _
	int tt; cin >> tt;
	while(tt--){
		cin >> n;
		g = vector<vector<int>>(n);
		for(int i = 0 ; i < n; i++){
			int a, b; cin >> a >> b; a--; b--;
			g[a].pb(b); g[b].pb(a);
		}
		bfs(0);
		cout << ans << endl;
	}
	exit(0);
}
