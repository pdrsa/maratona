//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
// #define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int32_t main(){ _
	int tt; cin >> tt;
	while(tt--){
		int n, q; cin >> n >> q;
		vector<int> points(n);
		set<pair<int, int>> pos;
		for(int i = 0; i < n; i++) pos.insert({0, i});
		int ans = 0;
		for(int qq = 1; qq <= q; qq++){
			auto ini = *pos.begin();
			
			int x, p; cin >> x >> p; x--;
			pos.erase({-points[x], x});
			points[x] += p;
			pos.insert({-points[x], x});

			if((*pos.begin()).second != ini.second) ans = qq;
		}

		cout << ans << endl;
	}
	exit(0);
}
