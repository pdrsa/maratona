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
	bool ok = false;
	for(int i = 0; i < int(s.size()) - 2; i++)
		if(s[i] == 'A' and s[i+1] == 'C' and s[i+2] == 'M') ok = true;
	if(ok) cout << "Fun!" << endl;
	else cout << "boring..." << endl;
	exit(0);
}
