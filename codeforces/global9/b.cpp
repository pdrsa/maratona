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
	int tt; cin >> tt;
	while(tt--){
		int n, m; cin >> n >> m;
		ll arr[n][m];
		bool ans = true;
		for (int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> arr[i][j];
			}
		}
		
		for (int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if((i == 0 or i == n-1) and arr[i][j] > 3) ans = false;
				if((j == 0 or j == m-1) and arr[i][j] > 3) ans = false;
				if((j == 0 or j == m-1) and (i == 0 or i == n-1) and arr[i][j] > 2) ans = false;
				if(arr[i][j] > 4) ans = false;
				if(ans == false) break;
			}
		}
		if(!ans) cout << "NO" << endl;
		else{
			cout << "YES" << endl;
			for (int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					if((j == 0 or j == m-1) and (i == 0 or i == n-1)) cout << 2 << " ";
					else if((i == 0 or i == n-1)) cout << 3 << " ";
					else if((j == 0 or j == m-1)) cout << 3 << " ";
					else cout << 4 << " ";
				}
				cout << endl;
			}
		}
	}
	exit(0);
}
