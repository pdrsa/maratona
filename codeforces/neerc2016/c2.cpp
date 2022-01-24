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

int32_t main(){ _
	// freopen("A.in","r",stdin);
	// freopen("A.out","w",stdout);
	string a, b; cin >> a >> b;
	set<string> s;
	string pre;
	for(int i = 0; i < a.size(); i++){
		pre.pb(a[i]);
		for(int j = int(b.size()) - 1; j >= 0; j--){
			string ans = pre;
			for(int k = j; k < int(b.size()); k++) ans.pb(b[k]);
			s.insert(ans);
		}
	}
	//for(auto z: s) cout << z << endl;
	cout << s.size() << endl;
	exit(0);
}
