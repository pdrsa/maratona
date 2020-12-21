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
const int MAX = 1e6 + 2;

int main(){ _
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		vector<ll> a(MAX+1);
		int maxi = -INF;
		for(int i = 0; i < n; i++){
			int z; cin >> z;
			maxi = max(maxi, z);
			a[z]++;
		}
		for(int i = 1; i <= maxi; i++){
		  	if(a[i] == 0) continue;
			for(int j = 2*i; j <= maxi; j += i){
				a[i] += a[j]; a[j] = 0;
			}
		}
		
		ll ans = 0;
		for(int i = 1; i <= maxi; i++) ans += (a[i] * i);
		cout << ans << endl;
	}
	exit(0);
}
