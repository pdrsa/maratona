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
		int n, m; cin >> n >> m;
		int mt[n][m];
		int n1 = 0, n0 = 0;
		int m1 = 0, m0 = 0;
		int ans = 0;
		int dis = (n+m) % 2 == 0 ? (n+m-2)/2 : INF;
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				bool flag = false;
				cin >> mt[i][j];
				if((i == 1 and j == 0) or (i == 0 and j == 1)) flag = true;
				if((i == n-1 and j == m-2) or (i == n-2 and j == m-1)) flag = true;
				if((i == 0 and j == 0) or (i == n-1 and j == m-1)) continue;
				if(i+j == n+m-2-i-j) continue;
				
				if(!flag){
					if(mt[i][j] == 1) n1++;
					else n0++;
				}

				else{
					if(mt[i][j] == 1) m1++;
					else m0++;
				}
			}
		}

		ans += min(n1, n0);
		ans += min(m1, m0);
		if(mt[0][0] != mt[n-1][m-1]) ans++;
		cout << ans << endl;
		

	}
	exit(0);
}
