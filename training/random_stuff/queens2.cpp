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

int n;
vector<vector<bool>> ans(n, vector<bool> (n, false));

bool checkSafe(vector<ii> q){
	for(auto queen:q){
		int x = queen.f;
		int y = queen.s;
		for(int i = 0; i < n; i++){
			if (ans[i][y] and i != x) return false;
			if (ans[x][i] and i != y) return false;
			if(i != 0){
				if (x-i >= 0 and y-i >= 0 and ans[x-i][y-i]) return false;
				if (x-i >= 0 and y+i < n  and ans[x-i][y+i]) return false;
				if (x+i < n  and y-i >= 0 and ans[x+i][y-i]) return false;
				if (x+i < n  and y+i < n  and ans[x+i][y+i]) return false;
			}
		}
	}
	return true;
}

int main(){ _
	cin >> n;
	vector<ii> q;

	int j = 0;
	for(int i = 0; i < n; i++){
		ans[i][j%n] = true;
		q.pb({i, j%n});
		j+=2;
	}

	/*for(auto u: ans){
		for(auto p: u){
		if(p) cout << "Q|";
		else cout << " |";
		}
		cout << endl;
		for(int i = 0; i < n; i++) cout << "--";
		cout << endl;
	}
	cout << endl;*/
	if(checkSafe(q)) cout << "Show de Bola" << endl;
	else cout << "Deu biziu" << endl;
	exit(0);
}
