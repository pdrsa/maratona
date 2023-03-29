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
		ll n, x; cin >> n >> x;
		vector<ll> v(n); for(ll &i: v) cin >> i;
		ll cur1 = 0, maxi1 = 0;
		for(int i = 0; i < n; i++){
			cur1 += v[i];
			if(cur1 < 0) cur1 = 0;
			maxi1 = max(maxi1, cur1);
		}
		cout << maxi1 << " ";
		for(int z = 1; z <= n; z++){
			
			ll maxi = 0;
			ll cur  = 0;
			for(int l = 0, r = 0; r < n; r++){
				
				cur += v[r];
				if(r - l + 1 <= z) cur += x;
				maxi = max(maxi, cur);

				while((cur <= 0 or v[l] < -x or r == n-1) and l < r){
					if(r - l + 1 <= z) cur -= x;
					cur -= v[l]; l++;
					maxi = max(maxi, cur);
				}
				maxi = max(maxi, cur);			
			}

			maxi = max(maxi, cur);
			cout << maxi << " ";
		}
		cout << endl;
	}
	exit(0);
}
