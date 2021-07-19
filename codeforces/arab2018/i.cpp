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
	//#warning FILE IN 
    freopen("icecream.in", "r", stdin);
	int tt; cin >> tt;
	while(tt--){
		int n, k; cin >> n >> k;
		vector<ii> c(n);
		for(int i = 0; i < n; i++){
			cin >> c[i].f; c[i].s = i;
		}
		vector<int> h(n); for(int &i: h) cin >> i;
		sort(c.begin(), c.end());
		vector<int> ans;
		
		for(int i = 0; i < n; i++)
			if(c[i].f <= c[k-1].f) ans.pb(h[c[i].s]);
		sort(ans.rbegin(), ans.rend());
		
		ll hap = 0;
		for(int i = 0; i < k; i++) hap += ans[i];
		cout << c[k-1].f << " " << hap << endl;
	}

	exit(0);
}
