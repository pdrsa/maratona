//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define f first
#define s second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int32_t main(){ //_
	int k, n; cin >> k >> n;
	int kit = k/n;

	vector<int> c(n);
	vector<int> blank(k);

	for(int i = 0; i < k; i++){
		cin >> blank[i];
		blank[i]--;
		if(blank[i] == -2) blank[i] = 0;
		c[blank[i]]++;
	}
	
	set<pair<int, int>> s;
	for(int i = 0; i < n; i++) s.insert({c[i], i});
	
	vector<pair<int, int>> ans;
	bool error = false;

	while(!s.empty()){
		pair<int, int> a = *s.begin();
		int rem = a.f % kit;

		if(rem == 0){
			int count = a.f;
			pair<int, int> print = {a.s, a.s};
		
			while(count--) ans.pb(print);
			s.erase(a);
			continue;
		}

		pair<int, int> b  = *s.rbegin();
		pair<int, int> na = {a.f - rem,         a.s};
		pair<int, int> nb = {b.f - (kit - rem), b.s};

		// Don't have enough
		if(nb.f < 0){
			error = true;
			break;
		}
		
		int count = kit;
		pair<int, int> print = {a.s, b.s};
		while(count--) ans.pb(print);
		
		s.erase(a), s.erase(b);
		s.insert(na), s.insert(nb);

	}
	assert(ans.size() == k);
	
	if(error) cout << "No" << endl;
	else{
		cout << "Yes" << endl;
		for(int color: blank){
			for(int i = 0; i < ans.size(); i++){
				if(ans[i].f == color or ans[i].s == color){
					cout << ans[i].f + 1 << " " << ans[i].s + 1 << endl;
					ans[i] = {-1, -1};
					break;
				}
			}
		}
	}

	exit(0);
}
