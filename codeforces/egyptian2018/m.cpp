//JP - Not in Kansas Anymore
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;


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
	// #warning FILE IN
	freopen("business.in", "r", stdin);
	int tt; cin >> tt;
	while(tt--){
		int n, m; cin >> n >> m;
		
		vector<tuple<int, int, int>> s(n);
		for(auto &[x,q,r]: s) cin >> x >> q >> r;
		
		vector<pair<int, int>> c(m);
		for(auto &[y,d]: c) cin >> y >> d;

		vector<tuple<int, int, int>> li; // Order(Pos), Type Event, Index
										 // Type 0 Open Shop
										 // Type 1 Client
										 // Type 2 Close shop

		for(int i = 0; i < n; i++){
			auto [x, q, r] = s[i];
			li.emplace_back(x, 0, i);
			li.emplace_back(x + r, 2, i);
		}
		for(int i = 0; i < m; i++){
			auto [y,d] = c[i];
			li.emplace_back(y, 1, i);
		}

		sort(li.begin(), li.end());
		vector<int> ans(m);
		ord_set<ii> ost;
		int size = 0;

		// Sweep
		for(auto [p, t, i]: li){
			if(t == 0){
				auto [x,q,r] = s[i];
				ost.insert({q-x, i});
				size++;
			}
			else if(t == 1){
				auto [y,d] = c[i];
				ans[i] = size - ost.order_of_key({d-y, -INF});
			}
			else{
				auto [x,q,r] = s[i];
				ost.erase({q-x, i});
				size--;
			}
		}

		for(int u: ans) cout << u << " ";
		cout << endl;
		
	}

	exit(0);
}
