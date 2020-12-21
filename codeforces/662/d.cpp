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
const ll LINF = 0x3f3f3f3f3f3f3f3afll;


char g[2001][2001];
bool v[2001][2001];

vector<ii> mv = ({1,0},{0,1},{-1,0},{0,-1});

bool can(int x, int y, char z){
	return x < n and x > 0 and y < m and y > 0 and !v[x][y] and g[x][y] == z;
}

ll bfs(int x, int y) {
	if(!can(x, y, g[x][y])) return 0;
	queue<ii> q;

	v[x][y] = true;
	q.push({x, y});
	

	while(!q.empty()) {
		ii vt = q.front(); q.pop();
		for(auto u : mv){
			char a = g[vt.f][vt.s];
			int i = vt.f + u.f; int j = vt.s+u.s;
			if(can(i, j, a)){
				v[i][j] = true;



				q.push({i,j});
			}
		}
	}
}

int main(){ _
	int n, m; cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> d[i][j];
	
	ll ans = 0;
	memset(d, false, sizeof d);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			ans += bfs[i][j];
	

	exit(0);
}
