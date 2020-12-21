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

ll comb(ll x){
	if(x < 3) return 0;
	if(x == 3) return 1;
	return (x * (x-1) * (x-2))/6;
}

int main(){ _
	int tt; cin >> tt;
	while(tt--){
		ll n; cin >> n;
		vector<ll> a(n); for(ll &i: a) cin >> i;
		sort(a.begin(), a.end());
		//for(auto i: a) cout << i << " ";
		//cout << endl;

		ll l = 0, r = 0;
		ll ans = 0;
		ll pastc = 0;

		while(r < n){
			ll old = l;
			while(l < n and r > 0 and a[l] == a[old]) l++;
			ans -= comb(pastc - (l - old));

			while(r < n and a[r] - a[l] <= 2) r++;
			pastc = r-l;
			//cout << "pastc " << pastc << endl;
			ans += comb(pastc);
		}

		cout << ans << endl;
	}
	exit(0);
}
