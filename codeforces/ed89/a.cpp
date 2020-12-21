#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
	int t; cin >> t;
	while(t--){
		ll a, b; cin >> a >> b;
		ll ma = max(a,b);
		ll mi = min(a,b);
		if(ma/2 >= mi) cout << mi << endl;
		else{
			ll ans = min(a/3, b/3);
			a -= ans*3; b -= ans*3;
			ans *= 2;
			ma = max(a,b); mi = min(a,b);
			ans += min(ma/2,mi);
			cout << ans << endl;
		}
	}
	exit(0);
}
