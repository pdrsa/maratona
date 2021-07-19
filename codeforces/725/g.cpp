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

ll a, b;

bool bb(ll x, ll y, ll m){

	ll i = 0;
	if(x >= a*i + b*(m-i) and y >= (a*(m-i)) + b*i) return true;
	if(y >= a*i + b*(m-i) and x >= (a*(m-i)) + b*i) return true;

	i = (m/2);
	if(x >= a*i + b*(m-i) and y >= (a*(m-i)) + b*i) return true;
	if(y >= a*i + b*(m-i) and x >= (a*(m-i)) + b*i) return true;

	return false;
}

int main(){ _
	int tt; cin >> tt;
	while(tt--){
		ll x, y; cin >> x >> y >> a >> b;
		ll r = min({(x+y)/(a+b), x/min(a,b), y/min(a,b)});
		ll l = max(0LL, r-1);
		//cout << min({(x+y)/(a+b), x/min(a,b), y/min(a,b)}) << endl;
		// cout << "Entre " << l << " e " << r << endl;
		while(l < r){
			ll m = (l+r+1)/2;
			if(bb(x, y, m)) l = m;
			else r = m-1;
		}
		cout << r << endl;
	}
	exit(0);
}
