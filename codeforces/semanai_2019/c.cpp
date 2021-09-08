#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5 + 10;

vector<pair<int, bool>> g[MAX];

tuple<ll, ll, ll> solve(int v, int p, ll zer, ll one) {
	ll ret = 0;

	for (auto [u, on] : g[v]) if (u != p) {
		
		auto [zer_, one_, ret_] = solve(u, v, 1, 0);
		ll rzer = (on == 1 ? one_ : zer_);
		ll rone = (on == 1 ? zer_ : one_);
		
		ret += ret_ + zer * rone + one * rzer;
		
		zer += rzer, one += rone;
	}

	//cout << "solve(" << v << ", " << p << ", " << zer << ", " << one << ") = {" << zer << ", " << one << ", " << ret << "}" << endl;
	return {zer, one, ret};
}

int main(){ _

	int n;
	cin >> n;
	vector<tuple<int, int, int>> edges(n - 1);
	for (auto& [v, u, w] : edges) {
		cin >> v >> u >> w;
		v--, u--;
	}

	ll ans = 0;
	for (int p = 0; p < 60; p++) {
		//cout << "p = " << p << endl;
		for (int i = 0; i < n; i++) g[i].clear();
		for (auto [v, u, w] : edges) {
			bool on = w & (1ll << p);
			g[v].emplace_back(u, on), g[u].emplace_back(v, on);
		}
		ans += (1ll << p) * get<2>(solve(0, -1, 1, 0));
	}

	cout << ans << endl;
	
	exit(0);
}
