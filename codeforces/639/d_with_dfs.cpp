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

// DFS
// Finds connected components

// Time complexity: O(v+e)

vector<vector<int> > adj(1e6);
vector<int> v;

void dfs(int s) {
	v[s] = 1;
	for (auto u: adj[s]) {
		if(v[u] == 0) {
			dfs(u);
		}	
	}
}

int main(){ _
	int n, m;cin >> n >> m;
	bool t[n][m];
	char aux;

	bool ft, ff, ans = true;
	bool er = false, ec = false;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> aux;
			if (aux == '#') t[i][j] = true;
			else t[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++){
		if(!ans) break;
		ft = false;
		ff  = false;
		for (int j = 0; j < m; j++){
			if (j == m-1 and !ft and !t[i][j]) er = true;
			if (t[i][j] and ft and ff){
				ans = false;
				break;
			}
			else if(!t[i][j] and ft) ff = true;
			else if(t[i][j]) ft = true;
		}
	}

	for (int j = 0; j < m; j++){
		if(!ans) break;
		ft = false;
		ff  = false;
		for (int i = 0; i < n; i++){
			if (i == n-1 and !ft and !t[i][j]) ec = true;
			if (t[i][j] and ft and ff){
				ans = false;
				break;
			}
			else if(!t[i][j] and ft) ff = true;
			else if(t[i][j]) ft = true;
		}
	}

	if (!ans or (ec and !er) or (er and !ec)){
		cout << -1 << endl;
		exit(0);
	}

	int blabla = m*n;
	while(blabla--) v.pb(-1);

	int x;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if(!t[i][j]) continue;
			x = i*m + j;
			v[x] = 0;
			//left
			if (j != 0 and t[i][j-1]) adj[x].pb(x-1);
			//right
			if (j != m-1 and t[i][j+1]) adj[x].pb(x+1);
			//up
			if (i != 0  and t[i-1][j]) adj[x].pb(x-m);
			//down
			if (i != n-1 and t[i+1][j]) adj[x].pb(x+m);
		}
	}
	
	bool full;
	int act = 0;
	int comp = 0;
	while(true){
		full = true;
		for (int i = act; i < n*m; i++){
			if (v[i] == 0){
				act = i;
				full = false;
				break;
			}
		}
		if (full) break;
		else{
			comp++;
			dfs(act);
		}
	}

	cout << comp  << endl;

	exit(0);
}
