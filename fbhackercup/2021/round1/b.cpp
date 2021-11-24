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
	int tt; cin >> tt;
	for(int t = 0; t < tt; t++){
		cout << "Case #" << t+1 << ": ";
		int n, m, a, b; cin >> n >> m >> a >> b;
		if(a < n+m-1 or b < n+m-1) cout << "Impossible" << endl;
		else{
			cout << "Possible" << endl;
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					if(i == 0 and j == 0)     cout << a - (n+m-2) << " ";
					else if(i == n-1 and j == 0) cout << b - (n+m-2) << " ";
					else cout << 1 << " ";
				}
				cout << endl;
			}
		}
	}
	exit(0);
}
