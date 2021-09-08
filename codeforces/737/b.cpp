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
		int n, k; cin >> n >> k;
		vector<int> v(n);
		for(int i = 0; i < n; i++) cin >> v[i];
		
		vector<int> ov = v;
		sort(ov.begin(), ov.end());
		ov.resize(unique(ov.begin(), ov.end()) - ov.begin());
		for (int& i : v)
			i = lower_bound(ov.begin(), ov.end(), i) - ov.begin();

		vector<int> f(n);
		for(int i = 0; i < n; i++) f[v[i]]++;

		int ans = 1;
		f[v[0]]--;
		for(int i = 1; i < n; i++){
			f[v[i]]--;

			if(v[i] == v[i-1]) continue;
			if(v[i] == v[i-1]+1 and f[v[i-1]] == 0) continue;

			ans++;
		}
		//cout << ans << endl;
		cout << (ans > k ? "No" : "Yes") << endl;
	}
	exit(0);
}
