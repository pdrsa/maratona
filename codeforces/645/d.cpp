#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll ton(ll n){ return (n * (n+1))/2;}

int main(){ _
	ll n, k; cin >> n >> k;
	vector<ll> a(2*n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i+n] = a[i];
	}
	n *= 2;
	vector<ll> h;
	vector<ll> d;

	h.pb(ton(a[0]));
	d.pb(a[0]);
	for(int i = 1; i < n; i++){
		h.pb(h.back() + ton(a[i]));
		d.pb(d.back() + a[i]);
	}

	ll ans = 0;

	for(int i = n/2; i < n; i++){
		ll dl = d[i] - k;
		ll mt = upper_bound(d.begin(), d.end(), dl) - d.begin();
		ll actual = h[i] - h[mt];
		dl = d[mt] - dl;
		if(dl > 0){
			actual += ton(a[mt]) - ton(a[mt] - dl);
		}
		ans = max(ans, actual);
	}

	cout << ans << endl;

	exit(0);
}
