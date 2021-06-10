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
	vector<ii> v(n);
	for(ii &i:v) cin >> i.f >> i.s;
	sort(v.begin(), v.end());
	vector<int> s(n); vector<ii> e(n);
	for(int i = 0; i < n; i++){
		s[i] = v[i].f;
		e[i] = {v[i].s, i};
	}
	sort(e.begin(), e.end());
	
	int ans = 0, l = 0, r = 0;
	while(r < n){
		if(e[r].s == l){
			ans++;
			l = upper_bound(s.begin(), s.end(), e[r].f) - s.begin();
		}
		else if(e[r].s > l) l++;
		else r++;
	}

	cout << ans << endl;
	exit(0);
}
