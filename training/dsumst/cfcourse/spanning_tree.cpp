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
const int MAX = 2e5 + 5;

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
	for(int i = 1; i <= n; i++) comp[i] = i;
	vector<tuple<int,int,int>> ed;
	while(m--){
		int a, b, w; cin >> a >> b >> w;
		ed.pb({w,a,b});
	}
	ll ans = 0;
	sort(ed.begin(), ed.end());

	for(auto [w,a,b]: ed) if(uni(a,b)) ans += w;
	
	cout << ans << endl;
	exit(0);
}

