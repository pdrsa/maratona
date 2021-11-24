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

int32_t main(){ // _
	int n; cin >> n;
	vector<int> h(n); for(int &i: h) cin >> i;
	sort(h.begin(), h.end());
	int q;
	while(q--){
		int x, y; cin >> x >> y;
		int targ = (y-x);

		int best = -1, idx = -1;
		int l = 0, r = n;
		while(l < r){
			int m = (l+r+1)/2;
			// cout << l << " " << r << " " << m << endl;
			if(abs(h[m] - targ) > abs(h[m] - best) and h[m] < y){
				best = abs(h[m]); idx = m;
			}

			if(h[m] > targ) r = m - 1;
			else l = m;
		}
		cout << idx+1 << endl;
	}
	exit(0);
}
