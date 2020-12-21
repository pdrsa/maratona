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

int main(){ //_
	ll n, h; cin >> n >> h;
	
	vector<iill> a(n+1);a[0] = {0,0};
	for(int i = 1; i <= n; i++) cin >> a[i].f >> a[i].s;
	sort(a.begin(), a.end());
	ll l = 0, r = 0;
	ll dist = 0;
	ll stp = 0;
	ll enp = 0;
	ll ans = 0;

	while(r <= n){
		
		while(dist + (a[r].f - enp) >= h){
			dist -= (a[l].f - a[stp].s);
			stp = l;
			//cout <<"l++" <<  " dist -> " << dist << endl;
			l++;
		}

		while(r <= n and enp + (h-dist) > a[r].f){
			dist += a[r].f - enp;
			enp = a[r].s;
			//cout << "r++" << " dist -> " << dist << endl;
			r++;
		}

		enp += (h-dist);
		dist = h;
		//cout << "sp = " << a[stp].f << " enp = " << enp;
		ans = max(ans, (enp - a[stp].f));
		//cout << "Max = " << ans << endl;
		//cout << "l " << l << " r " << r << endl;
	}
	cout << ans << endl;
	exit(0);
}
