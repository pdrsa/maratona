// Time: (ubiratan, EduardoFernandes, pedrosa)
// pedrosa

//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
// #define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e5 + 50;
const int MOD = 1e9 + 7;

int p[MAX];
int sz[MAX];

int find(int x){
	return p[x] = (p[x] == x ? x : find(p[x]));
}

void uni(int x, int y){
	x = find(x), y = find(y);
	if(x == y) return;
	if(sz[x] < sz[y]) swap(x, y);
	
	sz[x] += sz[y];
	p[y]  = x;
}

int32_t main(){ _
	int tt; cin >> tt;
	while(tt--){
		int n, m; cin >> n >> m;
		for(int i = 0; i < n; i++) p[i] = i, sz[i] = 1;
		while(m--){
			int a, b; cin >> a >> b;
			a--, b--;
			uni(a, b);
		}
		set<int> ans;
		for(int i = 0; i < n; i++) ans.insert(find(i));
		ll zz = 1;
		for(auto u: ans){
			zz *= sz[u];
			zz %= MOD;
		}

		cout << ans.size() << " " << zz << endl;
	}
	exit(0);
}
