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

bool subs(string a, string b){
	if(a.size() > b.size()) return false;
	
	for(int i = 0; i < (b.size() - a.size() + 1); i++){

		for(int j = 0; j < a.size(); j++){
			if(b[i+j] != a[j]) break;
			
			if(j == a.size() - 1) return true;
		}

	}

	return false;
}

int main(){ _
	int n; cin >> n;
	vector<pair<int, string>> a(n);

	for(auto &s:a) cin >> s.s;
	
	for(auto &s: a){
		for(auto w: a){
			//cout << s.s << " and " << w.s << " = " << subs(s.s, w.s) << endl;
			if(subs(s.s, w.s)) s.f++;
		}
	}
	
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	vector<string> ans;
	
	int prev = n;
	for(int i = 0; i < n; i++){
		//cout << a[i].f << endl;
		if(a[i].f < n-i) break;
		
		ans.pb(a[i].s);
	}

	if(ans.size() == n){
		cout << "YES" << endl;
		for(auto u: ans) cout << u << endl;
	}
	else cout << "NO" << endl;

	exit(0);
}
