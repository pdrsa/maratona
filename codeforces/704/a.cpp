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
	int t; cin >> t;
	while(t--){
		ll p, a, b, c; cin >> p >> a >> b >> c;
		if(p%a == 0 or p%b == 0 or p%c == 0) cout << 0 << endl;
		else cout << min({a - (p%a), b - (p%b), c - (p%c)}) << endl;
	}
	exit(0);
}
