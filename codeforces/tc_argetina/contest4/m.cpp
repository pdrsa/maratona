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

int log(int x){
	if(x == 1) return 0;
	return 1 + log(x/2);
}

int main(){ _
	int n; cin >> n;
	vector<int> a(n); for(int &i: a) cin >> i;
	sort(a.begin(), a.end());
	int k = (log(n)/2) + 1;
	ll ans = 0;

	int c = 0;
	for(int i = 1; i <= n; i *= 3){
		for(int j = 0; j < i and j <= n; j++){
			ans += a.back() * (k - c); a.pop_back();
		}
		c++;
	}
	cout << ans << endl;
	exit(0);
}
