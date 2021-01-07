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
		vector<vector<int>> g(n);
		vector<int> w(n);
		ll ans = 0;
		for(int &i:w){ cin >> i; ans += i; }

		for(int i = 0; i < n-1; i++){
			int a, b; cin >> a >> b;
			a--, b--;
			g[a].pb(b), g[b].pb(a);
		}

		vector<ii> s;

		for(int i = 0; i < n; i++)
			if(g[i].size() > 1) s.pb({w[i], g[i].size() - 1});
		
		s.pb({0, INF});
		sort(s.rbegin(), s.rend());
		
		cout << ans << " ";
		for(int i = 0, p = 0; i < n-2; i++){
			if(s[p].s == 0) p++;
			ans += s[p].f; s[p].s--;
			cout << ans << " ";
		}
		cout << endl;
	}
	exit(0);
}
