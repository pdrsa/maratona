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
	ll n;
	double p;
	cin >> n >> p;
	vector<bool> b(n);
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		if(s == "halfplus") b[i] = true;
	}
	reverse(b.begin(), b.end());

	ll ap = 0;
	ll ans = 0;
	for(int i = 0; i < n; i++){
		ap *= 2;
		if(b[i]) ap++;
		ans += double(double(ap)/2) * p;
	}
	cout << ans << endl;
	exit(0);
}
