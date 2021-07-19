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
		int n, k; cin >> n >> k;
		vector<int> t(k);
		vector<int> p(k);
		for(int &i: p) cin >> i;
		for(int &i: t) cin >> i;
		vector<ii> men(k), mai(k);

		for(int i = 0; i < k; i++){
			men[i] = {p[i], t[i] - p[i]};
			mai[i] = {p[i], t[i] + p[i]};
		}
	
		sort(men.begin(), men.end());
		sort(mai.begin(), mai.end());
		
		for(int i = 1; i < k; i++) men[i].s    = min(men[i].s, men[i-1].s);
		for(int i = k-2; i >= 0; i--) mai[i].s = min(mai[i].s, mai[i+1].s);
		
		/*for(auto [a, b]: men) cout << a << " " << b << " | ";
		cout << endl;
		for(auto [a, b]: mai) cout << a << " " << b << " | ";
		cout << endl;
		*/

		for(int i = 1; i <= n; i++){
			int fw = INF, bw = INF;

			ii search = {i, INF};
			auto it = upper_bound(men.begin(), men.end(), search);
			if(it != men.begin()) bw = (*(it-1)).s;
			
			search = {i, -INF};
			auto it2 = lower_bound(mai.begin(), mai.end(), search);
			if(it2 != mai.end()) fw = (*it2).s;
			//cout << fw << " " << bw << " ";
			cout << min((bw+i), (fw-i)) << " ";
		}
		cout << endl;
	}
	exit(0);
}
