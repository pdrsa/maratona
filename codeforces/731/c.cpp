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
int main(){ _
	int tt; cin >> tt;
	while(tt--){
		int k, n, m; cin >> k >> n >> m;
		vector<vector<int>> ac(2);
		
		for(int i = 0; i < n; i++){
			int a; cin >> a;
			ac[0].pb(a);
		}
		for(int i = 0; i < m; i++){
			int a; cin >> a;
			ac[1].pb(a);
		}
		// for(int i: ac[1]) cout << i << " ";
		// cout << endl;
		
		vector<int> ans;
		int i = 0, j = 0;

		while(i < ac[0].size() or j < ac[1].size()){
			if(i < ac[0].size()){
				if(ac[0][i] == 0){
					ans.pb(0); k++;
					i++; continue;
				}
				else if(ac[0][i] <= k){
					ans.pb(ac[0][i]); i++;
					continue;
				}
			}

			if(j < ac[1].size()){
				if(ac[1][j] == 0){
					ans.pb(0); k++;
					j++; continue;
				}
				if(ac[1][j] <= k){
					ans.pb(ac[1][j]); j++;
					continue;
				}
			}

			break;
		}

		//cout << ans.size() << endl;
		if(ans.size() == (m+n)){
			for(int z: ans) cout << z << " ";
			cout << endl;
		}
		
		else cout << -1 << endl;
	}
	exit(0);
}
