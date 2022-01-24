// Time: (ubiratan, EduardoFernandes, pedrosa)

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
const int MAX = 2e5 + 10;

int g[MAX];

int p[MAX];

int find(int x){
	return p[x] = (p[x] == x ? x : find(p[x]));
}

void uni(int x, int y){
	x = find(x), y = find(y);
	p[x] = y;
}

vector<int> pai(MAX, -1);
vector<ll> cost(MAX);

ll dfs(int x){
	ll ans = cost[x];
	if(pai[g[x]] != -1){
		int v = g[x];
		while(v != x) ans = min(ans, cost[v]), v = g[v];
	} else{
		pai[g[x]] = x;
		ans = min(ans, dfs(g[x]));
	}

	return ans;
}

int32_t main(){ _
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		p[i] = i;
		cin >> cost[i];
	}

	for(int i = 0; i < n; i++){
		int a; cin >> a; a--;
		g[i] = a;
		uni(i, a);
	}

	set<int> comps;
	for(int i = 0; i < n; i++) comps.insert(find(i));

	ll ans = 0;
	for(int u: comps){
		pai[u] = -2;
		ans += dfs(u);
	}
	
	cout << ans << endl;

	exit(0);
}
