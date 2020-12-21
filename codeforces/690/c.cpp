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
		if(n > 45){
			cout << -1 << endl;
			continue;
		}

		vector<int> ans;
		for(int j = 9; j > 0; j--){
			if(j < n){
				n -= j;
				ans.pb(j);
			}
			else{
				ans.pb(n);
				break;
			}
		}

		reverse(ans.begin(), ans.end());
		for(auto i:ans) cout << i;
		cout << endl;
	}
	exit(0);
}
