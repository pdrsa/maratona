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

vector<int> p;

int find(int x){
	return p[x] = (p[x] == x ? x : find(p[x]));
}

void uni(int x, int y){
	x = find(x), y = find(y);
	p[x] = y;
}

int main(){ _
	int n, m; cin >> n >> m;
	
	p = vector<int> (n+1); for(int i = 1; i <= n; i++) p[i] = i;

	vector<tuple<int, int, int>> ed;
	while(m--){
		int a, b, w; cin >> a >> b >> w;
		ed.pb({w,a,b});
	}
	sort(ed.begin(), ed.end());

	int ans = 0;
	for(auto [w, a, b]: ed){
		if(find(a) != find(b)){
			uni(a,b); ans = max(ans, w);
		}
	}

	cout << ans << endl;
	exit(0);
}
