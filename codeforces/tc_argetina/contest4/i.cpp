//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> iill;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void fail(){
	cout << -1 << endl;
	exit(0);
}

int main(){ _
	int n, m; cin >> n >> m;
	vector<vector<int>> c(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char a; cin >> a;
			if(a == '#') c[i][j] = -2;
			else c[i][j] = -1;
		}
	}
	
	int color;
	for(int j = 0; j < m; j++){
		for(int i = 1; i < n; i++){
			if(c[i-1][j] == -1 and c[i][j] == -1){
				color = (i%3)*3 + (j%3);
				c[i-1][j] = color, c[i][j] = color;
				i++;
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 1; j < m; j++){
			if(c[i][j-1] == -1 and c[i][j] == -1){
				color = (i%3)*3 + (j%3);
				c[i][j-1] = color, c[i][j] = color;
				j++;
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(c[i][j] == -1){
				// Check Up
				if(i and c[i-1][j] >= 0) c[i][j] = c[i-1][j];
				// Check Left
				else if(j and c[i][j-1] >= 0) c[i][j] = c[i][j-1];
				// Check Right
				else if(j < m-1 and c[i][j+1] >= 0) c[i][j] = c[i][j+1];
				// Check Down
				else if(i < n-1 and c[i+1][j] >= 0) c[i][j] = c[i+1][j];
			}
		}
	}
	
	for(auto u: c) for(int v: u) if(v == -1) fail();

	for(auto u: c){
		for(int v: u){
			if(v == -2) cout << '#';
			else if(v == -1) cout << '.';
			else cout << v;
		}
		cout << endl;
	}

	exit(0);
}
