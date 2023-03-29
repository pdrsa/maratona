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
		
		
		vector<ll> k(n); k[0] = max(v[0], 0LL);
		for(int i = 1; i < n; i++)
			k[i] = max(k[i-1] + v[i], 0LL);
		cout << *max_element(k.begin(), k.end()) << " ";

		vector<ll> nk(n);
		for(int z = 1; z <= n; z++){
			nk[0] = max(v[0]+x, 0LL);
			for(int i = 1; i < n; i++)
				nk[i] = max(k[i-1] + v[i] + x, 0LL);
			k = nk;

			cout << *max_element(k.begin(), k.end()) << " ";
		}
		cout << endl;
	}
	exit(0);
}
