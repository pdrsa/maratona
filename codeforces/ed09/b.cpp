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
const int MAX = 5e5 + 50;
vector<int> s;
string ab;

int n;


ll solve(){
	vector<ll> sum(n);
	sum[0] = ((ab[0] == 'B') ? s[0] : 0);
	for(int i = 1; i < n; i++) sum[i] = sum[i-1] + (ab[i] == 'B' ? s[i] : 0);
	// cout << "SUM " << sum[n-1] << endl;
	ll maxi = sum[n-1];
	ll cur = 0;

	for(int i = n-1; i >= 0; i--){
		if(ab[i] == 'A') cur += s[i];
		else cur -= s[i];
		ll pref  = (i ? sum[i-1] : 0);
		maxi = max(maxi, cur + pref);

	}

	return maxi;
}

int main(){ _
	cin >> n;
	s = vector<int>(n);
	for(int i = 0; i < n; i++) cin >> s[i];
	cin >> ab;
	ll ans = solve();
	//cout << ans << endl;
	reverse(s.begin(), s.end());
	reverse(ab.begin(), ab.end());

	ans = max(ans, solve());
	//cout << solve() << endl;
	cout << ans << endl;
	exit(0);
}
