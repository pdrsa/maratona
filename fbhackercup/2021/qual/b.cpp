//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

// #define int ll
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> iill;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int32_t main(){ _
	int ttt; cin >> ttt;
	for(int tt = 1; tt <= ttt; tt++){
		int n; cin >> n;
		
		// Read
		int g[n][n];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				char c; cin >> c;
				if(c == '.') g[i][j] = 1;
				if(c == 'O') g[i][j] = -3000;
				if(c == 'X') g[i][j] = 0;
			}
		}

		// Possibilities
		vector<int> p(2100);
		for(int i = 0; i < n; i++){
			int row = 0, col = 0;
			bool coinc = false;
			for(int j = 0; j < n; j++){
				row += g[i][j], col += g[j][i];
				if(g[i][j] == 1 and i == j) coinc = true;
			}
			if(row > 0) p[row]++;
			if(col > 0) p[col]++;

			// Corner do corner essa bosta que chatice kkkkk
			if(row == col and row == 1 and coinc)
				p[row]--;
		}

		ii ans = {-1, -1};

		for(int i = 1; i < 2100; i++){
			if(p[i] > 0){
				ans = {i, p[i]};
				break;
			}
		}
		
		cout << "Case #" << tt << ": ";
		if(ans.f == -1) cout << "Impossible" << endl;
		else cout << ans.f << " " << ans.s << endl;
	}
	exit(0);
}
