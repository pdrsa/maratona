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

vector<vector<int>> adj(1010);
int d[1010];

int bfs(int x) {
	memset(d, -1, sizeof d);	
	queue<int> q;

	d[x] = 0;	
	q.push(x);
	int n = -1;

	while(!q.empty()) {
		n++;
		int s = q.front(); q.pop();
		//if(n > 0) cout << "Node " << s << " removed!" << endl;
		for(auto u : adj[s]) if(d[u] == -1) {
			d[u] = d[s]+1;
			q.push(u);
		}
	}

	return n;
}

int main(){ _
	int t; cin >> t;
	while(t--){

		adj.assign(1010, {});
		int n, x; cin >> n >> x;
		int a, b;
		for(int i = 0; i < n-1; i++){
			cin >> a >> b;
			if(b != x)
				adj[a].pb(b);
			if(a != x)
				adj[b].pb(a);
		}
	
		int ans = 0;
		int si = adj[x].size();

		if(si < 2){
			cout << "Ayush" << endl;
			continue;
		}

		ans += si - 2;

		for(auto u: adj[x]){
			ans += bfs(u);
		}
		
		if(ans % 2 == 0) cout << "Ashish" << endl;
		else cout << "Ayush" << endl;

	}


	exit(0);
}
