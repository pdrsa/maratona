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
	ll n, x; cin >> n >> x;
	vector<ll> c(n); for(ll &i: c) cin >> i;
	sort(c.begin(), c.end());
	ll ans = 0;

	for(auto cha: c){
		ans += cha * x;
		if(x > 1) x--;
	}
	cout << ans << endl;
	exit(0);
}
