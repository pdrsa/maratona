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


int main(){ _
	int n, m; cin >> n >> m;
	vector<int> dg(n);
	vector<ii> ed;

	while(m--){
		int a, b; cin >> a >> b;
		a--; b--;
		dg[a]++;
		dg[b]++;

		ed.pb({min(a,b), max(a,b)});
	}
	
	sort(ed.begin(), ed.end());
	
	int ans = INF;
	for(auto u: ed){
		auto [a, b] = u;

		for(int i = 0; i < n; i++){
			if(i == a or i == b) continue;

		
			ii s = {min(a,i), max(a,i)};
			bool fa = binary_search(ed.begin(), ed.end(), s);
			
			s = {min(b,i), max(b,i)};
			bool fb = binary_search(ed.begin(), ed.end(), s);
			
			if(fa and fb) ans = min(ans, dg[a] + dg[b] + dg[i]);
		}
	}

	cout << (ans == INF ? -1 : ans - 6) << endl;


	exit(0);
}

