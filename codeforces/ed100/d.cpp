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
		vector<ll> b(n); for(ll &i:b) cin >> i;
		int f = 0, s = 0;

		for(int i: b){
			if(i <= n) f++;
			if(i >= n) s++;
		}

		int ans = 0;

		for(int x = 0; x <= n; x++){
			if(x >= (f+1)/2 and (n-x) >= (s+1)/2) ans++;
		}

		cout << ans << endl;
	}
	exit(0);
}
