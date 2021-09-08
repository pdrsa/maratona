//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

// #define int ll
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> iill;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> g(26);
vector<int> d;

void bfs(int start){
	d.assign(26, -1);
	d[start] = 0;
	queue<int> q; q.push(start);
	while(!q.empty()){
		int v = q.front(); q.pop();
		for(int u: g[v]) if(d[u] == -1){
			d[u] = d[v] + 1;
			q.push(u);
		}
	}
}


int32_t main(){ _
	int ttt; cin >> ttt;
	for(int tt = 1; tt <= ttt; tt++){
		string s; cin >> s;
		for(int i = 0; i < 26; i++) g[i].clear();
		
		// Read Graph
		int k; cin >> k;
		while(k--){
			char A, B; cin >> A >> B;
			int a = A - 'A', b = B - 'A';
			g[b].pb(a);
		}

		// Brute
		int ans = INF;
		for(int i = 0; i < 26; i++){
			int t = 0;
			bfs(i);
			for(char C: s){
				int c = C - 'A';
				if(d[c] == -1){
					t = INF;
					break;
				}
				else t += d[c];
			}
			ans = min(ans, t);
		}
		cout << "Case #" << tt << ": ";
		cout << (ans == INF ? -1 : ans) << endl;
	}
	exit(0);
}
