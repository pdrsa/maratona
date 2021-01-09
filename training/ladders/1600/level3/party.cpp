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

void dfs(int x){
	for(int i: g[x]){
		if(d[i] == -1){
			d[i] = d[x]+1;
			dfs(i);
		}
	}
}

int main(){ _
	int n; cin >> n;
	g = vector<vector<int>> (n);
	vector<int> sup(n);
	for(int i = 0; i < n; i++){
		cin >> sup[i];
		if(sup[i] == -1) continue;
		sup[i]--;
		g[i].pb(sup[i]), g[sup[i]].pb(i);
	}
	
	int maxi = 0;
	for(int i = 0; i < n; i++){
		if(sup[i] == -1){
			d = vector<int> (n, -1);
			d[i] = 0;
			dfs(i);
			maxi = max(maxi, *max_element(d.begin(), d.end()));
		}
	}
	
	cout << maxi + 1 << endl;
	
	exit(0);
}
