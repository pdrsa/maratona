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
	int n; cin >> n;
	string s; cin >> s;
	vector<int> ans;
	for(int i = 0; i < (1 << n); i++){
		int a = 0;
		for(int j = 0; j < n; j++){
			if(i & (1 << j)) a += int(s[j]);
		}
		ans.pb(a);
	}
	sort(ans.begin(), ans.end());
	for(int i: ans) cout << i << " ";
	cout << endl;
	exit(0);
}
