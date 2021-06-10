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
	int n, k; cin >> n >> k;
	string s, ans; cin >> s;

	for(int i = 0; i < s.size(); i++){
		int t    = (s[i] - 'a');
		if(t <= 12){
			int rem  = min(25 - t, k);
			ans.pb(char('a' + rem + t));
			k -= rem;
		}
		else{
			int rem = min(t, k);
			ans.pb(char('a' + t - rem));
			k -= rem;
		}
	}
	if(k == 0) cout << ans << endl;
	else cout << -1 << endl;
	exit(0);
}
