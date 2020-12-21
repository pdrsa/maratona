#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
	int t; cin >> t;
	while (t--){
		ll n; cin >> n;
		ll fl = 1;
		ll s;
		ll ans = 0;
		if (n < 2){
			cout << 0 << endl;
			continue;
		}
		while(1){
			s = fl * 2 + fl - 1;
			if (n - s >= 0){
				n = n - s;
				fl++;
			}
			else{
				ans++;
				fl = 1;
				if (n < 2) break;
			}
		}
		cout << ans << endl;
	}
	exit(0);
}
