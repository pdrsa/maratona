//JP - Not in Kansas Anymore
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
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

template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;

int main(){ _
	int tt; cin >> tt;
	while(tt--){
		int n, lv, rv; cin >> n >> lv >> rv;
		ord_set<ii> s;
		vector<int> v;
		ll ans = 0;
		for(int i = 0; i < n; i++){
			int a; cin >> a;

			int le = s.order_of_key({(rv-a) + 1, -INF});
			int tl = s.order_of_key({(lv-a), -INF});
			
			s.insert({a, i});
			//cout << a << ":" << le << " " << tl << endl;
			ans += ll(le) - ll(tl);
		}
		
		cout << ans << endl;
	}
	exit(0);
}
