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

void test_case(){
	int n; cin >> n;
	string s; cin >> s;
	int n0 = 0;
	vector<int> ans;
	for(char c: s) if(c == '0') n0++;
	for(int i = 0; i < n; i++){
		if(s[i] == '1' and i < n0) ans.pb(i);
		if(s[i] == '0' and i >= n0) ans.pb(i);
	}
	if(ans.size() > 0){
		cout << 1 << endl;
		cout << ans.size() << " ";
		for(int i: ans) cout << i+1 << " ";
		cout << endl;
	} else cout << 0 << endl;
	
}

int32_t main(){ _
	int tt; cin >> tt;
	while(tt--) test_case();
	exit(0);
}
