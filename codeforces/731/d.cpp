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
		vector<int> a(n); for(int &i: a) cin >> i;
		vector<int> ans;
		// reverse(a.begin(), a.end());
		
		ans.pb(0);
		for(int i = 1; i < n; i++){
			int cur = 0;
			// cout << (a[i+1] & a[i] ) << " ";
			for(int j = 0; j <= 30; j++)
				if(a[i-1] & (1 << j) and !(a[i] & (1 << j)))
					cur += (1 << j);
			a[i] = (a[i] ^ cur);
			ans.pb(cur);
		}
		//cout << endl;
		//reverse(ans.begin(), ans.end());
		for(int i: ans) cout << i << " ";
		cout << endl;
	}
	exit(0);
}
