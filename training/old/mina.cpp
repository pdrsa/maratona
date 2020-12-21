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

int d[100][100];
int m[100][100];

vector<ii> mv = {{1,0},{-1,0},{0,1},{0,-1}};

int n;

bool can(int x, int y){ return x >= 0 and x < n and y >= 0 and y < n;}

void djikstra(int x, int y){
	set<vector<int>> q;

	memset(d, -1, sizeof d);
	q.insert({0, x, y});
	vector<int> aux;

	while(!q.empty()){
		aux      = *q.begin();
		q.erase(q.begin());
		x    = aux[1];
		y    = aux[2];
		int dist = aux[0];
		if(d[x][y] != -1) continue;
		d[x][y]  = dist;
		for (auto u:mv){
			int i = x+u.f;
			int j = y+u.s;
			if (!can(i,j)) continue;
			if (d[i][j] != -1) continue;
			q.insert({dist+m[i][j], i, j});
		}
	}
}



int main(){ _
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> m[i][j];
		}
	}

	djikstra(0,0);
	cout << d[n-1][n-1] << endl;
	exit(0);
}
