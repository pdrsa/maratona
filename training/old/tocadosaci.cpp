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

int n, m;
int d[1000][1000];
vector<vector<int>> g;
vector<ii> mv = {{-1,0},{1,0},{0,-1},{0,1}};

bool can(int x, int y){
	return (x < n and x >= 0 and y < m and y >= 0 and g[x][y] != 0);
}

void bfs(int x, int y) {
	queue<ii> q;
	memset(d, -1, sizeof d);
	
	d[x][y] = 1;
	q.push({x,y});
	
	while (!q.empty()) {
		auto it = q.front(); q.pop();
		for (auto u : mv) {
			int i = it.f+u.f;
			int j = it.s+u.s;
			if (!can(i,j)) continue;
			if (d[i][j] != -1) continue;
			d[i][j] = d[it.f][it.s] + 1;
			q.push({i, j});
		}
	}
}

int main(){ _
	cin >> n >> m;
	g.resize(n);
	int sti, stj, eni, enj, aux;
	for (int i = 0; i < n; i++){
		g[i].resize(m);
		for (int j = 0; j < m; j++){
			cin >> aux;
			g[i][j] = aux;
			if (aux == 2){
				sti = i;
				stj = j;
			}
			if (aux == 3){
				eni = i;
				enj = j;
			}
		}
	}
	
	bfs(sti, stj);

	cout << d[eni][enj] << endl;


	exit(0);
}
