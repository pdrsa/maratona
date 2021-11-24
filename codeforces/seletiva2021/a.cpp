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
	int n; cin >> n;
	vector<string> f;
	vector<string> s;
	vector<string> t;
	string cap;
	while(n--){
		string a, b; cin >> a >> b;
		if(b == "rat") f.pb(a);
		else if(b == "woman" or b == "child") s.pb(a);
		else if(b == "captain") cap = a;
		else t.pb(a);
	}
	for(auto c: f) cout << c << endl;
	for(auto c: s) cout << c << endl;
	for(auto c: t) cout << c << endl;
	cout << cap << endl;
	exit(0);
}
