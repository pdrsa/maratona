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

vector<int> p;

int n, m;

vector<vector<int>> g;
vector<bool> d;

void dfs(int x){
	d[x] = true;
	for(int u: g[x]) if(!d[u]) dfs(u);
}

bool check(int k){
	g = vector<vector<int>>(n);
	d.assign(n, false);
	int cc = 0; // Connected Components
	for(int i = 0; i < n; i++){
		int a = ((i - k) + n) % n;
		int b = p[i];
		g[a].pb(b), g[b].pb(a);
	}
	for(int i = 0; i < n; i++) if(!d[i]) dfs(i), cc++;
	
	return (n - cc) <= m;
}

int main(){ _
	int tt; cin >> tt;
	while(tt--){
		cin >> n >> m;
		p.resize(n);
		for(int &i:p){ cin >> i; i--; }
		
		vector<int> r(n);
		for(int i = 0; i < n; i++){
			int shift = i - p[i];
			if(shift >= 0) r[shift]++;
			else r[n+shift]++;
		}
		
		vector<int> ans;
		for(int i = 0; i < n; i++)
			if((n - r[i] <= 2 * m) and check(i)) ans.pb(i);
		
		cout << ans.size() << " ";
		for(int i: ans) cout << i << " ";
		cout << endl;
	}
	exit(0);
}
