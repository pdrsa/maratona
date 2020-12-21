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

int d[50][50];
int n, m;
char mz[50][50];
vector<ii> mv{{-1,0},{1,0},{0, -1},{0,1}};

bool can(int x, int y){
	return  (x >= 0 and x < n and y >=0 and y < m and mz[x][y] != '#');
}

void bfs(int x, int y){
	memset(d, -1, sizeof d);	
	queue<ii> q;
	
	d[x][y] = 1;

	if(can(x,y)) q.push({x,y});
	
	while(!q.empty()) {
		ii s = q.front(); q.pop();
		for(auto u : mv){
			int i = s.f + u.f;
			int j = s.s + u.s;
			if(can(i, j) and d[i][j] == -1) {
				d[i][j] = 1;
				q.push({i, j});
			}
		}
	}
}


int main(){ _
	int t; cin >> t;
	while(t--){
		cin >> n >> m;
		vector<ii> g;
		vector<ii> b;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> mz[i][j];
				if(mz[i][j] == 'G')g.pb({i,j});
				if(mz[i][j] == 'B')b.pb({i,j});
			}
		}
		
		bool ans = true;
		for(auto bad: b){
			for(auto u: mv){
				int x = bad.f + u.f;
				int y = bad.s + u.s;
				if(x >= 0 and x < n and y >= 0 and y < m){
					if (mz[x][y] == 'G') ans = false;
					else mz[x][y] = '#';
				}
			}
		}
		
		/*for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cout << mz[i][j];
			}
			cout << endl;
		}*/

		if(!ans){
			cout << "No" << endl;
			continue;
		}
		
		bfs(n-1, m-1);

		for(auto u: g){
			if(d[u.f][u.s] == -1) ans = false;
		}

		if(ans) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	exit(0);
}
