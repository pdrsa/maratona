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

vector<int> comp;
vector<vector<int>> st;

int find(int x){
	return x == comp[x] ? x : comp[x] = find(comp[x]);
}

void uni(int x, int y){
	x = find(x); y = find(y);
	if(st[x].size() > st[y].size()) swap(x,y);
	comp[x] = y;
	for(auto u: st[x]) st[y].pb(u);
}

int main(){ _
	int n; cin >> n;
	comp = vector<int> (n+1);
	st = vector<vector<int>> (n+1);
	
	for(int i = 1; i <= n; i++){
		st[i].pb(i);
		comp[i] = i;
	}


	for(int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		uni(a,b);
		if(i == n-1){
			if(st[find(a)].size() < st[find(b)].size()) swap(a,b);

			for(auto u: st[find(a)]) cout << u << " ";
			cout << endl;
		}
	}

	exit(0);
}
