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

vector<int> comp(3e5+2);
vector<int> mini(3e5+2);
vector<int> maxi(3e5+2);
vector<int> sz(3e5+2, 1);

int find(int x){
	return (x == comp[x] ? x : comp[x] = find(comp[x]));
}

void uni(int x, int y){
	x = find(x), y = find(y);
	comp[x] = y;
	mini[y] = min(mini[x], mini[y]);
	maxi[y] = max(maxi[x], maxi[y]);
	if(x != y) sz[y] += sz[x];
}

int main(){ _
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++) comp[i] = mini[i] = maxi[i] = i;
	while(m--){
		string s;
		int x;
		cin >> s >> x;
		if(s == "get") cout << mini[find(x)] << " " << maxi[find(x)] << " " << sz[find(x)] << endl;
		else{
			int y; cin >> y;
			uni(x,y);
		}
	}
	exit(0);
}
