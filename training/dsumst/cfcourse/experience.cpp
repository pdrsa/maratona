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
const int MAX = 2e5 + 3;

vector<int> xp(MAX);
vector<int> comp(MAX);
vector<int> sz(MAX, 1);
vector<int> extra(MAX);

int find(int x){
	return x == comp[x] ? x : find(comp[x]);
}

void uni(int x, int y){
	x = find(x), y = find(y);
	if(x == y) return;
	if(sz[x] > sz[y]) swap(x, y);

	comp[x] = y;
	extra[x] = xp[y];

	sz[y] += sz[x];
}

int get(int x){
	if(x == comp[x]) return xp[x];

	return xp[x] - extra[x] + get(comp[x]);
}

int main(){ _
	int n, m; cin >> n >> m;

	for(int i = 1; i <= n; i++) comp[i] = i;

	while(m--){
		string s; cin >> s;
		if(s == "add"){
			int x, v; cin >> x >> v;
			xp[find(x)] += v;
		} else if(s == "join"){
			int x, y; cin >> x >> y;
			uni(x, y);
		} else{
			int x; cin >> x;
			cout << get(x) << endl;
		}
	}
	exit(0);
}
