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

vector<bool> v;
vector<vector<int>> adj;

void dfs(int s) {
	v[s] = true;
	for (auto u: adj[s])
		if(!v[u])
			dfs(u);
}

int main(){ _
	int n, m; cin >> n >> m;
	v.resize(n, false);
	adj.resize(n);
	for (int i = 0; i < m; i++){
		int a, b; cin >> a >> b;
		adj[a-1].pb(b-1);
		adj[b-1].pb(a-1);
	}
	
	int cont = 0;

	for (int i = 0; i < n; i++){
		if (!v[i]){
			cont++;
			dfs(i);
		}
	}

	cout << cont << endl;

	exit(0);
}
