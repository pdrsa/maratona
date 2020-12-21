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
const int MAX = 1e4+10;

vector<ll> a(MAX);
ll n, k;

bool poss(ll m){
	ll ans = 0;
	for(int i = 0; i < n; i++){
		if(a[i] >= m) ans += a[i]-m;
		else{
			ans -= ((m-a[i]) * 100LL)/k;
		}
	}
	if (ans >= 0) return true;
	else return false;
}


int main(){ 
	cin >> n >> k;
	k = 100-k;
	ll maior = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i] *= 1e9;
		maior = max(maior,a[i]);
	}

	ll l = 0, r = maior;
	while(l<r){
		//cout << l << " " << r << endl;
		ll m = (l+r+1)/2;
		if(poss(m)) l = m;
		else r = m-1;
	}
	
	long double ans = l;
	cout << fixed << setprecision(9);
	cout << ans/1e9 << endl;

	exit(0);
}
