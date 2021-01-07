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

vector<ll> dp;
vector<ll> a;
int n;

ll solve(int i){
	if(i >= n) return 0;
	if(dp[i] != -1) return dp[i];
	return dp[i] = a[i] + solve(i + a[i]);
}


int main(){ _
	int tt; cin >> tt;
	while(tt--){
		cin >> n;
		dp = vector<ll> (n, -1);
		a = vector<ll> (n);
		for(ll &i:a) cin >> i;
		
		for(int i = 0; i < n; i++) solve(i);
		
		ll ans = 0;

		for(ll p: dp) ans = max(ans, p);

		cout << ans << endl;
	}
	exit(0);
}
