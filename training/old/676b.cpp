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

int main(){ _
	int n, t; cin >> n >> t;
	double g[10][10];
	
	memset(g, 0, sizeof g);
	g[0][0] = t;
	for(int i = 1; i < 10; i++){
		g[i][0] = max(g[i-1][0] - 1, 0.0) * 0.5;
		g[i][i] = max(g[i-1][i-1] - 1, 0.0) * 0.5;
		for(int j = 1; j < i; j++){
			g[i][j] = max(g[i-1][j] - 1, 0.0) * 0.5 + max(g[i-1][j-1] - 1, 0.0) * 0.5;
		}
	}
	
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			if(g[i][j] > 0.9999999) ans++;
			//cout << g[i][j] << " ";
		}
		//cout << endl;
	}

	cout << ans << endl;

	exit(0);
}
