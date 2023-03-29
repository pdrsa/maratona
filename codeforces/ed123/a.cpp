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
	int tt; cin >> tt;
	while(tt--){
		string s; cin >> s;
		bool fail = false;
		vector<bool> v(3);
		for(char c: s){
			if(c == 'r') v[0] = true;
			if(c == 'g') v[1] = true;
			if(c == 'b') v[2] = true;
			if(c == 'R') fail = fail or !v[0];
			if(c == 'G') fail = fail or !v[1];
			if(c == 'B') fail = fail or !v[2];
		}
		cout << (fail ? "NO" : "YES") << endl;
	}
	exit(0);
}
