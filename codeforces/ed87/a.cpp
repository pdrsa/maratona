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
		ll a, b, c, d; cin >> a >> b >> c >> d;
		if (b >= a){
			cout << b << endl;
			continue;
		}
		
		ll tim = a - b;
		ll bla;
		ll ble = c - d;
		
		if (ble <= 0){
			cout << -1 << endl;
			continue;
		}

		bla = (tim % ble) ? tim/ble + 1 : tim/ble;

		cout << b + (bla * c) << endl;

	}
	exit(0);
}
