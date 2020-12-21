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

ll mod(ll a, ll b){ return (a%b+b)%b;}


int main(){ _
	int t; cin >> t;
	while (t--){
		ll n; cin >> n;
		bool flag = true;
		vector<ll> arr(n);
		vector<ll> ans;
		for (int i = 0; i < n; i++) cin >> arr[i];
		for (int i = 0; i < n; i++)
			ans.pb(mod(i + arr[i], n));
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size() - 1; i++){
			if (ans[i] == ans[i+1]){
				cout << "NO" << endl;
				flag = false;
				break;
			}
		}
		if (flag) cout << "YES" << endl;
	}

	exit(0);
}
