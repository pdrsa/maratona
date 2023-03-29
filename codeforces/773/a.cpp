//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define f first
#define s second

// #define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int32_t main(){ _
	int tt; cin >> tt;
	while(tt--){
		vector<pair<int, int>> t(3);
		for(auto &[a,b]: t) cin >> a >> b;
		int ans = 0;
		if(t[0].s == t[1].s){
			if(t[2].s < t[0].s)
				ans = abs(t[0].f - t[1].f);
		}if(t[0].s == t[2].s){
			if(t[1].s < t[0].s)
				ans = abs(t[0].f - t[2].f);
		}if(t[1].s == t[2].s){
			if(t[0].s < t[1].s)
				ans = abs(t[1].f - t[2].f);
		}
		
		cout << ans << endl;
	}

	exit(0);
}
