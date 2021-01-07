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
const int MAX = 1e3 + 5;

vector<int> comp(MAX);

int find(int x){
	return (x == comp[x] ? x : comp[x] = find(comp[x]));
}

bool uni(int x, int y){
	x = find(x);
	y = find(y);
	comp[x] = y;

	return x != y;
}

int main(){ _
	int n, m; cin >> n >> m;
	vector<tuple<ll,int,int>> ed;

	while(m--){
		int a, b, w; cin >> a >> b >> w;
		ed.pb({w,a,b});
	}
	
	sort(ed.begin(), ed.end());
	
	ll ans = LINF;

	for(auto [z, tt, ttt]: ed){

		for(int i = 1; i <= n; i++) comp[i] = i;
		ll act = z;
		
		for(auto[w, a, b]: ed){
			if(find(a) != find(b) and w >= z){
				uni(a,b);
				act = max(act, w);
			}
		}

		bool ok = true;
		for(int i = 1; i < n; i++) if(find(i) != find(i+1)) ok = false;
		if(ok) ans = min(ans, (act - z));
	}

	if(ans == LINF) cout << "NO" << endl;
	else cout << "YES" << endl << ans;
	exit(0);
}


