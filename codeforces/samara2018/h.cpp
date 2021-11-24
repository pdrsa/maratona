//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define f first
#define s second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m, d;
vector<vector<int>> v;
vector<vector<int>> dist;

bool can(int x, int y){
	return x < n and x >= 0 and y < m and y >= 0 and dist[x][y] == -1 and v[x][y] == 0;
}

int bfs(int x, int y, int finix, int finiy) {
	if(v[x][y] != 0) return -1;
	vector<pair<int, int>> mv = {{1,0}, {0,1}, {-1,0}, {0,-1}};
	dist.assign(n, vector<int>(m, -1));
	queue<pair<int, int>> q;

	dist[x][y] = 0;
	q.push({x, y});
	
	while(!q.empty()) {
		pair<int, int> ver = q.front(); q.pop();
		for(auto u : mv){ 
			int i = ver.f + u.f;
			int j = ver.s + u.s;
			if(can(i, j)){
				dist[i][j] = dist[ver.f][ver.s] + 1;
				q.push({i,j});
			}
		}
	}

	return dist[finix][finiy];
}

int f(int i, int k){
	i = max(i, 0);
	i = min(i, k-1);
	return i;
}

void propagate(){
	// Up Down Left Right
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			v[i][j] = max({
			v[i][j], 
			v[f(i-1, n)][j] - 1, 
			v[f(i+1, n)][j] - 1,
		    v[i][f(j-1, m)] - 1, 
			v[i][f(j+1, m)] - 1});

	// Down Up Left Right
	for(int i = n-1; i >= 0; i--)
		for(int j = 0; j < m; j++)
			v[i][j] = max({
			v[i][j], 
			v[f(i-1, n)][j] - 1, 
			v[f(i+1, n)][j] - 1,
			v[i][f(j-1, m)] - 1, 
			v[i][f(j+1, m)] - 1});

	// Up Down Right Left
	for(int i = 0; i < n; i++)
		for(int j = m-1; j >= 0; j--)
			v[i][j] = max({
			v[i][j], 
			v[f(i-1, n)][j] - 1, 
			v[f(i+1, n)][j] - 1,
			v[i][f(j-1, m)] - 1, 
			v[i][f(j+1, m)] - 1});
	
	// Down Up Right Left	
	for(int j = m-1; j >= 0; j--)
		for(int i = n-1; i >= 0; i--)
			v[i][j] = max({
			v[i][j],
			v[f(i-1, n)][j] - 1, 
			v[f(i+1, n)][j] - 1,
			v[i][f(j-1, m)] - 1, 
			v[i][f(j+1, m)] - 1});
	
	// Left Right Up Down
	for(int j = 0; j < m; j++)
		for(int i = 0; i < n; i++)
			v[i][j] = max({
			v[i][j], 
			v[f(i-1, n)][j] - 1,
			v[f(i+1, n)][j] - 1,
			v[i][f(j-1, m)] - 1, 
			v[i][f(j+1, m)] - 1});

	// Left Right Down Up
	for(int j = 0; j < m; j++)
		for(int i = n-1; i >= 0; i--)
			v[i][j] = max({
			v[i][j],
			v[f(i-1, n)][j] - 1,
			v[f(i+1, n)][j] - 1,
			v[i][f(j-1, m)] - 1,
			v[i][f(j+1, m)] - 1});

	// Right Left Up Down
	for(int j = m-1; j >= 0; j--)
		for(int i = 0; i < n; i++)
			v[i][j] = max({v[i][j],
			v[f(i-1, n)][j] - 1,
			v[f(i+1, n)][j] - 1,
			v[i][f(j-1, m)] - 1,
			v[i][f(j+1, m)] - 1});
	
	// Right Left Down Up
	for(int j = m-1; j >= 0; j--)
		for(int i = n-1; i >= 0; i--)
			v[i][j] = max({
			v[i][j],
			v[f(i-1, n)][j] - 1,
			v[f(i+1, n)][j] - 1,
			v[i][f(j-1, m)] - 1, 
			v[i][f(j+1, m)] - 1});
}

int32_t main(){ _
	cin >> n >> m >> d;
	pair<int, int> start, finish;
	v.assign(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char c; cin >> c;
			if(c == 'S') start  = {i, j};
			if(c == 'F') finish = {i, j};
			if(c == 'M') v[i][j] = d+1;
		}
	}
	propagate();
	propagate();
	/*for(auto u: v){
		for(int a: u) cout << a << " ";
		cout << endl;
	}*/
	cout << bfs(start.f, start.s, finish.f, finish.s) << endl;
	exit(0);
}
