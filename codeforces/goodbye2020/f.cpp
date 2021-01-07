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
const int MAX = 5e5 + 2;
const int MOD = 1e9 + 7;

vector<int> comp(MAX);
vector<int> sz(MAX, 1);

int find(int x){
	return (comp[x] == x ? x : comp[x] = find(comp[x]));
}

bool uni(int x, int y){
	x = find(x), y = find(y);
	if(sz[x] < sz[y]) swap(x,y);

	comp[x] = y; sz[x] += sz[y];

	// Are in different comp?
	return (x != y);
}

int main(){ _
	int n, m; cin >> n >> m;
	for(int i = 1; i <= m; i++) comp[i] = i;
	
	vector<int> s;
	for(int i = 0; i < n; i++){
		int k, d1, d2;
		cin >> k >> d1;

		if(k > 1) cin >> d2;
		else d2 = m+1;
		
		if(uni(d1,d2)) s.pb(i+1);
	}
	
	ll ans = 1;
	for(int i = 0; i < s.size(); i++){
		ans *= 2; ans %= MOD;
	}

	cout << ans << " " << s.size() << endl;
	for(int i: s) cout << i << " ";
	cout << endl;
	
	exit(0);
}
