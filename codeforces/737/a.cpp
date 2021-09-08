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
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		vector<double> v(n);
		for(double &i: v) cin >> i;
		sort(v.rbegin(), v.rend());
		double ans = 0;
		for(int i = 1; i < n; i++) ans += v[i];
		ans /= (n-1);
		ans += v[0];
		cout << fixed << setprecision(7);
		cout << ans << endl;
	}
	exit(0);
}
