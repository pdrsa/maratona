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
typedef tuple<ll, ll, ll> t3;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
	int n, m, k; cin >> n >> m >> k;

	vector<ll> ans(n);
	for(ll &i: ans) cin >> i;
	
	vector<t3> op(m); for(auto &[l, r, d]: op) cin >> l >> r >> d;
	
	// Preperaring queries
	vector<int> q(m+1);
	while(k--){
		int x, y; cin >> x >> y;
		x--, q[x]++, q[y]--;
	}
	
	vector<ll> a(n+1);
	// Building queries and preparing array
	for(int i = 1; i <= m; i++){
		q[i] += q[i-1];
		if(q[i-1] > 0){
			auto [l, r, d] = op[i-1];
			l--, a[l] += (d * q[i-1]), a[r] -= (d * q[i-1]);
		}
	}

	for(int i = 1; i <= n; i++) a[i] += a[i-1];
	for(int i = 0; i < n; i++){
		ans[i] += a[i];
		cout << ans[i] << " ";
	}
	cout << endl;

	exit(0);
}
