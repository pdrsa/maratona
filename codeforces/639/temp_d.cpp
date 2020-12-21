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

int n, m;

vector<vector<bool>> t;
vector<vector<bool>> yet;

vector<ii> mv = {{1,0},{0,1},{0,-1},{-1,0}};

bool can(int i, int j){
	return i >= 0 and i < n and j >= 0 and j < m and t[i][j];
}

void bfs(int i, int j) {
	queue <ii> q;
	yet[i][j] = true;
	q.push({i,j});
	while(!q.empty()){
		auto it = q.front(); q.pop();
		for(auto u : mv){
			int row = it.f+u.f;
			int col = it.s+u.s;
			if (can(row, col)){
				if(!yet[row][col]){
					yet[row][col] = true;
					q.push({row,col});
				}
			}
		}
	}
}

int main(){ _
	cin >> n >> m;
	char aux;
	
	t.resize(n);
	yet.resize(n);

	bool ft, ff, ans = true;
	bool er = false, ec = false;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> aux;
			yet[i].resize(m);
			t[i].resize(m);
			if (aux == '#') {
				t[i][j]   = true;
				yet[i][j] = false;
			}
			else{
				t[i][j]   = false;
				yet[i][j] = true;
			}
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

	int comp = 0;
	bool goAgain = true;

    while(goAgain){
        goAgain = false;
        for (int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if (!yet[i][j]){
                    comp++;
                    bfs(i,j);
                    goAgain = true;
                    break;
                }
            }
            if (goAgain) break;
        }
    }

	cout << comp  << endl;

	exit(0);
}
