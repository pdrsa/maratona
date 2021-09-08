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
	int n, k; cin >> n >> k;
	vector<int> v(n); for(int &i: v) cin >> i;
	
	map<int, int> m;
	for(int i: v) m[i] = 0;
	
	//for(auto [key, value]: m) cout << key << ":" << value << endl;
	set<int> s;

	for(int l = 0, r = 0; r < n; ){
		while(r < n and r < l + k){
			m[v[r]]++;
			if(m[v[r]] == 1) s.insert(v[r]);
			if(m[v[r]] == 2) s.erase(v[r]);
			
			r++;
		}
		// Computar a resposta para esse intervalo
		if(s.empty()) cout << "Nothing" << endl;
		else cout << *s.rbegin() << endl;

		m[v[l]]--;
		if(m[v[l]] == 0) s.erase(v[l]);
		if(m[v[l]] == 1) s.insert(v[l]);
		
		l++;
	}

	exit(0);
}
