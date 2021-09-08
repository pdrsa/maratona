//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

// #define int ll
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> iill;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int32_t main(){ _
	int tt; cin >> tt;
	while(tt--){
		int n, q; cin >> n >> q;
		string s; cin >> s;
		vector<int> sum(n);
		
		sum[0] = (s[0] == '+' ? 1 : -1);
		for(int i = 1; i < n; i++){
			bool plus = !(i % 2);
			bool pos  = (s[i] == '+');
			sum[i] = sum[i-1];

			if(plus == pos) sum[i]++;
			else sum[i]--;
		}
		// for(int i: sum) cout << i << " ";
		// cout << endl;
		while(q--){
			int l, r; cin >> l >> r;
			r--, l--;
			int cSum = sum[r] - (l == 0 ? 0 : sum[l-1]);
			if(cSum == 0) cout << 0 << endl;
			else{
				if(cSum % 2 == 0) cout << 2 << endl;
				else cout << 1 << endl;
			}
		}
	}
	exit(0);
}
