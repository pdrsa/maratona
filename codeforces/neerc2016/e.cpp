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
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	string s; cin >> s;
	string ans;
	bool flag = false;
	for(int i = 0; i < int(s.size()); i++){
		if(flag){
			if(s[i] != '+' and s[i] != '-') ans.pb('+');
			if(s[i] != '0') flag = false;
		}

		if(s[i] == '-'){
			flag = true;
			ans.pb(s[i]);
			i++;
		}
		
		ans.pb(s[i]);
	}
	cout << ans << endl;
	exit(0);
}
