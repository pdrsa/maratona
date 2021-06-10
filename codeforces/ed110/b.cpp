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

/*bool comp(int a, int b){
	if(a % 2 == 0 and b % 2 != 0) return true;
	else return a > b;
}*/

int main(){ _
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		vector<int> v(n);
		for(int &i: v) cin >> i;
		int ans = 0;
		int m2 = 0;
		for(int i = 0; i < n; i++){
			if(v[i] % 2 == 0) m2++;
			for(int j = i + 1; j < n; j++){
				if((v[i] % 2 == v[j] % 2) and gcd(v[i], v[j]) > 1) ans++;
			}
		}
		
		ans += (m2 * (n - m2));
		cout << ans << endl;
	}
	exit(0);
}
