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
vector<bool> d;

vector<vector<int>> g(2005);
vector<vector<int>> q(2005);
 
void dfs1(int x){
	d[x] = true;
	for(int i: g[x]){
		if(!d[i]) dfs1(i);
	}
}

void dfs2(int x){
	d[x] = true;
	for(int i: q[x]){
		if(!d[i]) dfs2(i);
	}
}

int main(){ _
	int n; cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
			if(a[i][j] > 0){
				g[i].pb(j);
				q[j].pb(i);
			}
		}
	}
	
	bool ans = false;

	for(int j = 0; j < 1; j++){
		//if(!a[j][j]) continue;

		bool ok = true;

		d = vector<bool>(n);
		dfs1(j);
		for(auto u: d){
			if(!u){
				ok = false; break;
			}
		}
	
		d = vector<bool>(n);
		dfs2(j);
		for(auto u: d){
			if(!u){
				ok = false; break;
			}
		}

		if(ok){
			ans = true; break;
		}
	}
	
	cout << (ans ? "YES" : "NO") << endl;
	
	exit(0);
}
