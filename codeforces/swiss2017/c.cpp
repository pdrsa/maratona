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
		ll n; cin >> n;
		if(n % 3 == 0)
			cout << n/3 << " " << n/3 << " " << n/3 << endl;
		else if(n % 4 == 0)
			cout << n/2 << " " << n/4 << " " << n/4 << endl;
		else
			cout << "IMPOSSIBLE" << endl;
	}
	exit(0);
}
