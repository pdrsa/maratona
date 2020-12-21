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
	int t; cin >> t;
	while(t--){
		int n, m, a, b;
		cin >> n >> m >> a >> b;

		if (n*a != m*b){
			cout << "NO" << endl;
			continue;
		}
		else cout << "YES" << endl;
		
		bool ans[n][m];
		memset(ans, false, n*m);
		int aux = 0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<a; j++) {
				ans[i][(j+aux)%m] = true;
			}
			aux+=a;
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cout << ans[i][j];
			}
			cout << endl;
		}


	}
	exit(0);
}
