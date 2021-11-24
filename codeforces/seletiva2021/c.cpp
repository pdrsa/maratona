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
	int n; cin >> n;
	vector<int> p(n); for(int &i: p) cin >> i;
	sort(p.begin(), p.end());
	int q; cin >> q;
	while(q--){
		int val; cin >> val;
		int pos = upper_bound(p.begin(), p.end(), val) - p.begin();
		cout << pos << endl;
	}
	exit(0);
}
