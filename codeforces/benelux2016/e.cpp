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
const int MAX = 10100;

ll lim = LINF;

ll d[MAX];
vector<pair<int,int>> g[MAX]; // {vizinho, peso}

int n;

ll maxDist;

void dijkstra(int x) {
	for (int i = 0; i < n; i++) d[i] = LINF;
	d[x] = 0;
	priority_queue<pair<ll,int>> pq;
	pq.push({0,x});

	while (pq.size()) {
		auto [ndist,u] = pq.top(); pq.pop();
		if(-ndist > d[u]) continue;

		for (auto [idx,w] : g[u]) if (d[idx] > d[u] + w) {
			if(w > lim) continue;
			d[idx] = d[u] + w;
			pq.push({-d[idx], idx});
		}
	}
}

bool solve(ll mid){
	lim = mid;

	dijkstra(0);
	ll ans = d[n-1];
	return (ans <= maxDist);
}

int main(){ _
	int m, x; cin >> n >> m >> x;
	while(m--){
		int a, b, w; cin >> a >> b >> w;
		a--, b--;
		g[a].pb({b,w}), g[b].pb({a, w});
	}
	dijkstra(0);
	maxDist = d[n-1] * (100+ x) / 100;
	
	ll ini = 0, fim = 1e9 + 20;
	while(ini < fim){
		ll mid = (ini+fim)/2;
		if(solve(mid)) fim = mid;
		else ini = mid+1;
	}

	cout << ini << endl;

	exit(0);
}
