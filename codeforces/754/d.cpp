//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
// #define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 2e5 + 50;

vector<int> g[MAX];
multiset<int> gg[MAX];

int log2(int x){
	int n = 1;
	for(int i = 0; i < 50; i++){
		if(n >= x*2) return i;
		n *= 2;
	}
	return 0;
}

void test_case(){
	
	int n; cin >> n;

	for(int i = 0; i < n; i++){
		g[i].clear(); gg[i].clear();
	}

	for(int i = 0; i < n-1; i++){
		int a, b; cin >> a >> b;
		a--, b--;
		g[a].pb(b), g[b].pb(a);
	}	

	vector<pair<int, int>> s(n);
	for(int i = 0; i < n; i++) s[i] = {g[i].size(), i};
	sort(s.rbegin(), s.rend());


	multiset<int> p;
	for(int i = 1; i <= n; i++) p.insert(log2(i));
	vector<int> ans(n);

	for(int i = 0; i < n; i++){
		auto [a, idx] = s[i];

		for(int mini: p){
			if(!gg[idx].count(mini)){
				for(int j: g[idx]) gg[j].insert(mini);
				p.erase(mini);
				ans[idx] = mini;
				break;
			}
		}
	}

	for(int i: ans) cout << i << " ";
	cout << endl;
}	

int32_t main(){ _
	int tt; cin >> tt;
	while(tt--) test_case();
	exit(0);
}
