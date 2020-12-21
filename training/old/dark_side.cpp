#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
	int n; cin >> n;
	vector<ll> s(n);
	vector<ll> m(n);
	ll a, b, c;
	for(int i = 0; i < n; i++){
		cin >> a >> b >> c;
		s[i] = a+b+c;
		m[i] = s[i] - max({a,b,c}) + 2;
	}

	vector<ll> ch = m;
	sort(m.begin(), m.end());
	
	for(int i = 0; i < n; i++){
		auto low = upper_bound(m.begin(), m.end(), s[i]);
		int ans = low - m.begin();
		if(s[i] - ch[i] >= 0) ans--;
		cout << ans << " ";
}

	cout << endl;


	exit(0);
}
