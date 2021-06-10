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
	int n, m; cin >> n >> m;
	ll ans = 0;
	int last = -1;
	while(n--){
		int a; cin >> a;
		if(a > (m-a)) a = m-a;
		if(a < last) a = m-a;
		if(a < last){
			ans = -1;
			break;
		}
		last = a;
		ans += a;
	}
	cout << ans << endl;
	exit(0);
}
