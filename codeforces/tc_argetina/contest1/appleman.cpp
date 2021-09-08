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
	int n; cin >> n;
	ll ans = 0;
	vector<ll> a(n); for(ll &i: a) cin >> i;
	sort(a.begin(), a.end());
	ll c = 2;
	for(int i = 0; i < n; i++){
		if(i == n-1) c--;
		ans += c * a[i];
		c++;
	}
	cout << ans << endl;
	exit(0);
}
