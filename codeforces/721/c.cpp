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
		int n; cin >> n;
		vector<ll> es;
		map<int, vector<int>> m;
		ll ans = 0;

		for(int i = 0 ; i < n; i++){
			int a; cin >> a;
			
			if(m.count(a) == 0) m[a] = vector<int>(1, i+1);
			else m[a].pb(i+1);
		}

		for(auto it : m){
			vector<int> s = it.s;
			ll ac = 0;
			for(int i : s){
				ans += (ac * (n - i + 1));
				ac += i;
			}
		}

		cout << ans << endl;
	}
	exit(0);
}
