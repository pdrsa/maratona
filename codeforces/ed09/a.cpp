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
	ll count, p; cin >> count >> p;
	p = p/2;
	ll m = 1;
	vector<string> s(count);
	for(string &t:s) cin >> t;
	reverse(s.begin(), s.end());
	ll ap = 2;

	for(int i = 1; i < count; i++){
		ap *= 2;
		if(s[i] == "halfplus") ap += 2;
		m += (ap/2);
	}
	cout << m*p << endl;

	exit(0);
}
