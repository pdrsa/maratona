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
vector<vector<int>> g;

vector<int> d;
vector<int> p;

vector<int> dia;

void dfs(int x){
	for(int i: g[x]){
		if(d[i] != -1) continue;
		d[i] = d[x] + 1;
		p[i] = x;
		dfs(i);
	}
}

bool dfsc(int x){
	bool t = true;
	if(d[x] != 0 and g[x].size() > 2) t = false;
	for(int i: g[x]){
		if(d[i] != -1) continue;
		d[i] = d[x] + 1;
		t = t and dfsc(i);
	}
	return t;
}

int main(){ _
	int n; cin >> n;
	g = vector<vector<int>> (n);

	for(int i = 0; i < n-1; i++){
		int a, b; cin >> a >> b; a--; b--;
		g[a].pb(b); g[b].pb(a);
	}

	//Finding all vertices on diameter

	d = p = vector<int> (n, -1);
	d[0] = 0;
	dfs(0);
	int maxi = -INF, x;
	for(int i = 0; i < n; i++){
		if(d[i] > maxi){
			maxi = d[i]; x = i;
		}
	}

	d = p = vector<int> (n, -1);
	d[x] = 0;
	dfs(x);

	maxi = -INF;
	for(int i = 0; i < n; i++){
		if(d[i] > maxi){
			maxi = d[i]; x = i;
		}
	}
	
	vector<bool> isdi(n);

	while(p[x] != -1){
		dia.pb(x);
		isdi[x] = true;
		x = p[x];
	}
	dia.pb(x);
	isdi[x] = true;
	
	bool t = true;
	

	for(int u: dia){	
		
		for(int z: g[u]){
			if(!isdi[z]){
				d = vector<int> (n, -1);
				d[t] = 0;
				for(int s:dia) d[s] = 0;
				t = (t and dfsc(z));
			}
		}

	}

	cout << (t ? "Yes" : "No" ) << endl;

	exit(0);
}
