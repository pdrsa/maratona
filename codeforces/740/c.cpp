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
	while(tt--){
		int n; cin >> n;
		vector<ii> need(n);

		for(int i = 0; i < n; i++){
			cin >> need[i].s;
			for(int j = 0; j < need[i].s; j++){
				int p; cin >> p;
				p++;
				need[i].f = max(need[i].f, p-j);
			}
			need[i].s = -need[i].s;
		}

		sort(need.begin(), need.end());
		int ans = 0, power = 0;
		for(int i = 0; i < n; i++){
			ans = max(ans, need[i].f - power);
			power -= need[i].s;
		}

		cout << ans << endl;
	}
	exit(0);
}
