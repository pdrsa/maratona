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
	int tt; cin >> tt;
	while(tt--){
		int n, k; cin >> n >> k;
		vector<int> a(n); for(int i = 0; i < n; i++) cin >> a[i];
		int n1 = 0;
		vector<int> w(k); for(int i = 0; i < k; i++){
			cin >> w[i];
			if(w[i] == 1) n1++;
			w[i]--;
		}
		sort(w.begin(), w.end());
		sort(a.rbegin(), a.rend());
		ll ans = 0;
		int it;
		for(it = 0; it < k; it++){
			if(it < n1) ans += 2 * a[it];
			else ans+= a[it];
		}
		it--;
		for(int i = 0; i < k; i++){
			if(w[i] == 0) continue;
			it += w[i];
			ans += a[it];
		}
		
		cout << ans << endl;
	}
	exit(0);
}
