//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
// #define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int32_t main(){ _
	int n, k; cin >> n >> k;
	vector<ll> a(n);
	for(ll &i: a) cin >> i;
	ll sum = 0;
	int i = 2;
	int tot = n;
	for(int idx = 1; idx < tot; idx++){
		ll val = sum - ((n-i)*a[idx]*(i-1));
		// cout << idx +1 << " -> " << val << endl;
		if(val < k){
			cout << idx+1 << endl;
			n--;
		} else{
			sum += a[idx]*(i-1);
			i++;
		}
	}
	exit(0);
}
