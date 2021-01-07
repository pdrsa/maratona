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
	int tt; cin >> tt;
	while(tt--){
		ll w, h, n; cin >> w >> h >> n;
		ll ans = 1;
		while(w % 2 == 0){
			w /= 2; ans *= 2;
		}
		while(h % 2 == 0){
			h /= 2; ans *= 2;
		}
		if(ans >=n) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	exit(0);
}
