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

vector<vector<int>> md;
vector<int> dp;

int solve(int mask){
	if(mask == ((1 << (md.size())) - 1)) return 0;
	if(dp[mask] != -1) return dp[mask];
	
	int ans = INF;
	int f; // First not assigned
	for(int i = 0; i < md.size(); i++){
		if(!(mask & (1 << i))){
			f = i; break;
		}
	}

	// Trying all that haven't been used yet
	for(int i = f+1; i < md.size(); i++)
		if(!(mask & (1 << i))){
			int nextMask = mask;
			nextMask |= (1 << f);
			nextMask |= (1 << i);
			ans = min(solve(nextMask) + md[f][i], ans);
		}

	return dp[mask] = ans;
}

int main(){ _
	int n, k, l; cin >> n >> k >> l;
	
	// Read and transform
	vector<bool> A(n+2);
	for(int i = 1; i <= k; i++){
		int a; cin >> a;
		A[a] = 1;
	}
	vector<int> b;
	for(int i = 0; i <= n; i++)
		if(A[i] != A[i+1])
			b.pb(i);
	
	// Read moves and create Graph
	vector<int> moves(l);
	unique(moves.begin(), moves.end());
	for(int &i: moves) cin >> i;

	vector<vector<int>> g(n+1);
	for(int i = 0; i <= n; i++){
		for(int j: moves){
			if(i+j <= n)
				g[i].pb(i+j), g[i+j].pb(i);
		}
	}
	
	// BFS for each
	md.resize(b.size()); // Minimum Distances
	dp.assign(1 << (b.size() + 2), -1);
	for(int i = 0; i < b.size(); i++){
		vector<int> d(n+1, INF);
		queue<int> q; q.push(b[i]);
		d[b[i]] = 0;
		while(!q.empty()){
			int x = q.front(); q.pop();
			for(int u: g[x]) if(d[u] > d[x]+1){
				d[u] = d[x] + 1;
				q.push(u);
			}
		}
		
		for(int j: b){
			if(j == b[i]) md[i].pb(INF);
			else md[i].pb(d[j]);
		}
	}

	/*
	for(auto u: md.a){
		for(int i: u) cout << i << " ";
		cout << endl;
	}
	*/

	int ans = solve(0);
	//cout << md.size() << endl;
	//cout << ((1 << (md.size()+1)) - 1) << endl;
	cout << (ans >= INF ? -1 : ans) << endl;

	exit(0);
}
