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
		int n, m, x, y; cin >> n >> m >> x >> y;
		char s[n][m];
		string aux;
		for (int i = 0; i < n; i++){
			cin >> aux;
			for(int j = 0; j < m; j++){
				s[i][j] = aux[j];
			}
		}

		ll ans = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(s[i][j] == '.'){
					if(j != (m-1) and s[i][j+1] == '.' and y < 2 * x){
						ans += y;
						j++;
					}
					else ans+= x;
				}
			}
		}

		cout << ans << endl;
	}
	exit(0);
}
