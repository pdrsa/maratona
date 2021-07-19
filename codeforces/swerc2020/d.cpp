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

int n, m;
vector<vector<ii>> g;
vector<ll> d;

void dijkstra(int x){
	for (int i=0; i < n; i++) d[i] = LINF;
	d[x] = 0;
	priority_queue<pair<ll,int>> pq;
	pq.push({0,x});

	while (pq.size()) {
		auto [ndist,u] = pq.top(); pq.pop();
		if (-ndist > d[u]) continue;

		for (auto [idx,w] : g[u]) if (d[idx] > d[u] + w) {
			d[idx] = d[u] + w;
			pq.push({-d[idx], idx});
		}
	}
}

int main(){ _
	cin >> n >> m;
	g.resize(n);
	d.resize(n);
	int f; cin >> f >> f;
	while(m--){
		int a, b, w; cin >> a >> b >> w;
		g[a].pb({b, w}), g[b].pb({a, w});
	}
	dijkstra(0);

	set<ii> s;
	for(int i = 0; i < n; i++){
		if(d[i] * 2 < f){
			for(auto u: g[i]) s.insert(make_pair(u.f, i));
		}
	}
	cout << s.size()/2 << endl;
	exit(0);
}
