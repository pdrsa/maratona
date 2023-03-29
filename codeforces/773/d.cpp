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
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		list<int> lis;
		for(int i = 0; i < n; i++){
			int a; cin >> a; lis.pb(a);
		}
		
		auto l = lis.begin(), r = lis.begin();
		int lidx = 0, ridx = 0;
		vector<pair<int, int>> print;
		vector<int> segs;
		bool fail = false;
		while(l != lis.end()){
			r++; ridx++;
			while(*r != *l and r != lis.end()) r++, ridx++;
			if(*r != *l){
				fail = true;
				cout << -1 << endl;
				break;
			}
			auto found = r;

			// Filling the gap
			while(l != found){
				// Go front while equal
				if(*l == *r){
					l++, lidx++, r++, ridx++;
					continue;
				}

				// Inserts the two guys
				lis.insert(r, 2, *l); print.pb({ridx, *l});
				r--; r--;
			}
			l = r; lidx = ridx;
			segs.pb(ridx);
		}

		// Faiou
		if(fail) continue;
		
		cout << print.size() << endl;
		for(auto [p, c]: print) cout << p << " " << c << endl;
		cout << segs.size() << endl;
		for(int i = 0; i < segs.size(); i++){
			if(!i) cout << segs[i] << " ";
			else cout << segs[i] - segs[i-1] << " ";
		} cout << endl;
	}
	exit(0);
}
