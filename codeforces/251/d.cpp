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
	int n, m; cin >> n >> m;
	vector<ll> a(n), b(m);
	for(ll &i:a) cin >> i;
	for(ll &i:b) cin >> i;
	sort(a.begin(), a.end()), sort(b.rbegin(), b.rend());
	
	ll ans = 0;
	for(int i = 0; i < min(n,m) and a[i] < b[i]; i++) ans += b[i] - a[i];
	
	cout << ans << endl;
	exit(0);
}
