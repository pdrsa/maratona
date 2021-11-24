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
vector<vector<int>> g;
vector<int> color;
vector<bool> vis;
vector<vector<int>> val;
vector<int> orphan;
int process = 0;
int n;
string s;

void bfs(){
	queue<int> q;
	for(int x = 0; x < n; x++){
		if(orphan[x] == 0){
			val[x][s[x] - 'a'] = 1;
			q.push(x);
		}
	}

	while(!q.empty()){
		int v = q.front(); q.pop();
		process++;
		for(auto u: g[v]){

			for(int i = 0; i < 26; i++)
				val[u][i] = max(val[u][i], val[v][i]); // Merge Vals
			int let = s[u] - 'a';
			val[u][let] = max(val[u][let], val[v][let] + 1);

			orphan[u]--;
			if(orphan[u] == 0) q.push(u);
		}
	}
}

int32_t main(){ _
	int m; cin >> n >> m;
	cin >> s;
	g.resize(n);
	color.assign(n, 0);
	orphan.assign(n, 0);
	while(m--){
		int a, b; cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		orphan[b]++;
	}

	vis.resize(n);
	val.resize(n);
	for(int v = 0; v < n; v++)
		val[v].resize(26);

	bfs();
	
	int ans = -1;
	for(auto a: val)
		for(int x: a)
			ans = max(ans, x);

	cout << (process == n ? ans : -1) << endl;
	exit(0);
}
