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
	int n; cin >> n;
	int a, b = 0;
	vector<int> ans;
	while(n--){
		cin >> a;
		if(a == 1 and b != 0) ans.pb(b);
		b = a;
	}
	ans.pb(b);
	cout << ans.size() << endl;
	for(auto u:ans) cout << u << " ";
	cout << endl;
	exit(0);
}
