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
 
vector<ii> mv = {{0,1},{0,-1},{1,0},{-1,0}};
vector<vector<char>> v;
bool p[500][500];
int n, m, k;
 
bool can(int x, int y){
    return (x >= 0 and x < n and y >=0 and y < m and v[x][y] == '.') and !p[x][y];
}
 
void dfs(int x, int y) {
    if (k == 0) return;
 	p[x][y] = true;

    for (auto u: mv){
        int i, j;
        i = x + u.f;
        j = y + u.s;
        if (can(i, j)){
			k--;
			if(k > 0) dfs(i, j);
        }
    }
}
 
int main(){ _
    cin >> n >> m >> k;
    v.resize(n);
    int sti, stj;
	int cont = 0;
    for (int i = 0; i < n; i++){
        v[i].resize(m);
        for (int j = 0; j < m; j++){
            cin >> v[i][j];
            if (v[i][j] == '.'){
				cont++;
                sti = i; stj = j;
            }
        }
    }
 	
	k = cont - k;
    memset(p, false, sizeof p);
    dfs(sti, stj);
   
 
 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
			if (v[i][j] == '.' and !p[i][j]) cout << 'X';
			else cout << v[i][j];;
        }
        cout << endl;
    }
 
    exit(0);
}
