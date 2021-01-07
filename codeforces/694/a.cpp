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
		int n, x; cin >> n >> x;
		ll mini = 0;
		ll maxi = 0;
		while(n--){
			ll a; cin >> a;
			mini += a;
			maxi += (a+x-1)/x;
		}

		mini = (mini+x-1)/x;

		cout << mini << " " << maxi << endl;

	}
	exit(0);
}
