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
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
	int n; cin >> n;
	ll sq = 0;
	vector<ld> c(n);
	vector<ld> dif;
	ll nz = 0;
	for(ld &i: c){
		
		cin >> i;
		if(i == 0) nz++;
		ld sqroot = sqrt(i);
		if(sqroot == ll(sqroot)) sq++;
		else{
			ll sqr = ll(sqroot);
			ld dife = min(abs(i - (sqr*sqr)), abs(i - (sqr+1) * (sqr+1)));

			dif.pb(dife);
		}

	}

	if(sq == (n/2)) cout << 0 << endl;

	else if(sq > n/2){
		ll ans = (sq - (n/2));
		
		ll nzs = (sq - nz);
		
		ll zt = max(ans - nzs, 0LL);
		if(zt == 0) nzs = ans;
		cout << nzs + 2*(zt) << endl;
	}

	else{
		sort(dif.begin(), dif.end());
		ll ans = 0;
		for(int i = 0; i < ((n/2) - sq); i++) ans += dif[i];
		cout << ans << endl;
	}

	exit(0);
}
