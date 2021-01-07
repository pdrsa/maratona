//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define int long long

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> iill;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<int> dc;
vector<vector<int>> dp;
vector<vector<int>> g;

int n, m;

void bfs(int x){
	queue<int> q; q.push(x);
	dc[x] = 0;
	while(!q.empty()){
		int v = q.front(); q.pop();
		for(auto i: g[v]){
			if(dc[i] == -1){
				dc[i] = dc[v]+1; q.push(i);
			}
		}
	}
}

// Distance not using condition, distance using condition
int dfs(int x, int st){

	if(dp[x][st] != -1) return dp[x][st];

	if(dc[x] == 0) return dp[x][st] = 0;

	int ans = dc[x];
	for(auto i: g[x]){
		if(dc[x] < dc[i])
			ans = min(ans, dfs(i, st));
		else if(!st) ans = min(ans, dfs(i, 1));
	}

	return dp[x][st] = ans;
}

int32_t main(){ _
	int tt; cin >> tt;
	while(tt--){
		cin >> n >> m;
		g = vector<vector<int>>(n);
		dc = vector<int> (n, -1);
		dp = vector<vector<int>> (n, vector<int> (2, -1));

		while(m--){
			int a, b; cin >> a >> b;
			a--, b--;
			g[a].pb(b);
		}

		bfs(0);
		//for(int i: dc) cout << i << " "; cout << endl;
		
		for(int i = 0; i < n; i++) cout << dfs(i, 0) << " ";
		cout << endl;
	}
	exit(0);
}
