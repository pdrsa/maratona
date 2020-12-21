// BFS
//
// Complexity: 
// Time: O(v)

int d[MAX][MAX];
vector<ii> mv = ({1,0},{0,1},{-1,0},{0,-1});
//Version for moving in eight directions:
//vector<ii> mv = ({1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1});

//Replace lim1 and lim2 with your bounds (And add any further restriction)
bool can(int x, int y){
	return x < lim1 and x > 0 and y < lim2 and y > 0 and d[x][y] == -1;
}

void bfs(int x, int y) {
	memset(d, -1, sizeof d);	
	queue<ii> q;

	d[x][y] = 0;	
	q.push({x, y});
	
	while(!q.empty()) {
		ii v = q.front(); q.pop();
		for(auto u : mv){ 
			int i = v.f + u.f; int j = v.s+u.s;
			if(can(i, j)){
				d[i][j] = d[x][y] + 1;
				q.push({i,j});
			}
		}
	}
}
