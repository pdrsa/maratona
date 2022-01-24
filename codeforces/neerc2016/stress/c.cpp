//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
// #define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int32_t main(){ _
	// freopen("A.in","r",stdin);
	// freopen("A.out","w",stdout);
	string a, b; cin >> a >> b;
	vector<int> v(26); for(char c: b) v[c - 'a']++;
	v[b.back() - 'a'] = max(0, v[b.back() - 'a'] - 1);

	vector<int> l(26);
	for(int i = 0; i < int(a.size()); i++) l[a[i] - 'a'] = i;

	ll ans = b.size();
	for(int i = 1; i < int(a.size()); i++)
		ans += b.size() - v[a[i] - 'a'];
	cout << ans << endl;
	exit(0);
}
