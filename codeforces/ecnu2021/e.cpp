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

void dfs(int x){
	for(int v: g[x]) if(d[v] == -1){
		d[v] = d[x]+1;
		dfs(v);
	}
}

int main(){ _
	int n; cin >> n;
	g.resize(n);
	d.resize(n, -1);

	for(int i = 0; i < n-1; i++){
		int a, b; cin >> a >> b;
		a--, b--;
		g[a].pb(b), g[b].pb(a);
	}

	int a, b; cin >> a >> b;
	a--, b--;

	d[a] = 0;
	dfs(a);
	cout << (d[b] % 2 == 1 ? "Yes" : "No") << endl;

	exit(0);
}
