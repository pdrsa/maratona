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
	string low = "abcdefghijklmnopqrstuvwxyz";
	string up  = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string a; cin >> a;
	for(int i = 0; i < 26; i++) if(a[0] == low[i]) a[0] = up[i];
	cout << a << endl;
	exit(0);
}
