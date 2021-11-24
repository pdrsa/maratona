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
	string s; cin >> s;
	int n1 = 0, n0 = 0;
	for(char c: s)
		if(c == '1') n1++;
		else n0++;
	
	string ans;
	char print;
	if(n0 != n1){
		if(n0 > n1) print = '1';
		else print = '0';
		for(char c: s) ans.pb(print);
	} else{
		bool d = true;
		for(char c: s){
			if(c == '1' and d){
				ans.pb('0');
				d = false;
			}
			else ans.pb('1');
		}
	}
	
	cout << ans << endl;
	exit(0);
}
