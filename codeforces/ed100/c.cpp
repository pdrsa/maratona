//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define int long long

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> iill;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int32_t main(){ _
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		vector<ii> a(n);
		for(int i = 0; i < n; i++) cin >> a[i].f >> a[i].s;
		

		int x = 0, xstp = a[0].s, xgo = a[0].s;
		int t = a[0].f, tstp = a[0].f + abs(a[0].s);
		
		int ans = 0;

		for(int i = 1; i < n; i++){
			int xact = x;

			if(a[i].f >= tstp){
				tstp = a[i].f + abs(a[i].s - xstp);
				xact = xstp;
				xstp = a[i].s;
			}
			
			else{
				if(xstp > x) xact += (a[i].f - t);
				else xact -= (a[i].f - t);
			}

			if(min(xact, x) <= xgo and max(xact, x) >= xgo) ans++;
			
			//cout << "In order " << i << " robot moved from " << x << " to " << xact << endl;
			x = xact;
			t = a[i].f;
			xgo = a[i].s;
		}
		
		if(min(xstp, x) <= xgo and max(xstp, x) >= xgo) ans++;


		cout << ans << endl;
	}
	exit(0);
}
