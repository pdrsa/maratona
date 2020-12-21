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
	vector<ll> pw(33);
	pw[0] = 1;
	for(int i = 1; i < 33; i++) pw[i] = pw[i-1] * 2;
	reverse(pw.begin(), pw.end());

	int n; cin >> n;
	vector<ll> a(n); for(ll &i: a) cin >> i;
	vector<bool> v(n, true);
	sort(a.begin(), a.end());
	
	for(int i = 0; i < n; i++){
		v[i] = false;
		bool ok = false;
		
		for(ll p: pw){
			//cout << p << endl;
			if(a[i] >= p) break;

			ll w = (p - a[i]);
			//cout << a[i] << " : " << w << endl;
			int pos = lower_bound(a.begin(), a.end(), w) - a.begin();
			if(pos == i) pos++;

			if(pos < n and v[pos] and a[pos] == w){
				ok = true; break;
			}

		}

		if(ok) v[i] = true;
	}
	
	int ans = 0;
	for(auto u: v) if(!u) ans++;

	cout << ans << endl;
	exit(0);
}
