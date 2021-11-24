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

vector<pair<int, int>> mv = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int n, m;
vector<vector<pair<int, int>>> p;
vector<vector<char>> color;
vector<vector<bool>> vis;
bool found = false;

bool can(int x, int y){
	return x >= 0 and y >= 0 and x < n and y < m;
}

void dfs(int i, int j){
	vis[i][j] = true;
	for(auto [a, b]: mv){
		int x = i + a, y = j + b;
		if(can(x, y) and color[i][j] == color[x][y]){
			if(!vis[x][y]){
				p[x][y] = make_pair(i, j);
				dfs(x, y);
			} else if(p[i][j] != make_pair(x, y)) found = true;
		}
	}
}

int32_t main(){ _
	cin >> n >> m;
	p.assign(n, vector<pair<int, int>>(m, make_pair(-1, -1)));
	vis.assign(n, vector<bool>(m, false));
	color.assign(n, vector<char>(m));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> color[i][j];

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(!vis[i][j])
				dfs(i, j);

	cout << (found ? "Yes" : "No") << endl;
	exit(0);
}
