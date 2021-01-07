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
const int MAX = 1e5 + 2;

vector<int> comp(MAX);

int find(int x){
	return comp[x] = (x == comp[x] ? x : find(comp[x]));
}

void uni(int x, int y){
	x = find(x), y = find(y);
	comp[x] = y;
}

int main(){ _
	int n, m, tt; cin >> n >> m >> tt;
	for(int i = 1; i <= n; i++) comp[i] = i;
	
	set<ii> ed;
	while(m--){
		int a, b; cin >> a >> b;
		if(a > b) swap(a,b);
		ed.insert({a,b});
	}

	vector<pair<bool, ii>> req;
	while(tt--){
		string s; cin >> s;
		int a, b; cin >> a >> b;
		if(a > b) swap(a,b);
		ed.erase({a,b});
		req.pb({s == "ask", {a,b}});
	}
	
	reverse(req.begin(), req.end());
	
	for(auto[x,y]: ed) uni(x,y);

	vector<string> ans;
	for(auto [s, z]: req){
		auto [x,y] = z;
		if(s) ans.pb(find(x) == find(y) ? "YES" : "NO");
		else uni(x,y);
	}
	
	reverse(ans.begin(), ans.end());
	for(auto u: ans) cout << u << endl;

	exit(0);
}
