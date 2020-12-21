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
	ll n; cin >> n;
	vector<ll> a(n);
	for(ll &i: a) cin >> i;
	
	sort(a.begin(), a.end());
	
	vector<ll> t;

	ll pot = 1;
	t.pb(pot);
	while(pot <= 3e9 + 5){
		pot *= 2; t.pb(pot);
	}

//	for(auto u: t) cout << u << endl;

	ll ans = 1;
	vector<ll> ansr;
	for(ll p: t){
		for(int i = 0; i < n; i++){
			ll pos = a[i] + p;
			ll pos2 = pos + p;
			//cout << a[i] << " " << pos << " " << pos2 << endl;

			ll j = lower_bound(a.begin(), a.end(), pos) - a.begin();
			int act = 1;

			if(j < n and a[j] == pos){
				act++;
				j = lower_bound(a.begin(), a.end(), pos2) - a.begin();
				if(j < n and a[j] == pos2){
					act++;
				}
			}

			if(act > ans){
				ansr.clear();
				ans = act;
				ansr.pb(a[i]); ansr.pb(pos);
				if(ans == 3) ansr.pb(pos2);
			}

		}
		if(ans == 3) break;
	}
	
	cout << ans << endl;
	if(ans > 1) for(auto u: ansr) cout << u << " ";
	else cout << a[0];
	cout << endl;
	exit(0);
}
