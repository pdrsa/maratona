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

	vector<vector<int>> p(3, vector<int>(n+1));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < 3; j++)
			p[j][i+1] = p[j][i] + ((s[i] - 'a') == j);
	
	int ans = INF;
	vector<int> a;
	for(int i = 0; i < n; i++) if(s[i] == 'a') a.pb(i);
	
	for(int i = 0; i < int(a.size()) - 1; i++){
		int l = a[i], r = a[i+1];

		int na = p[0][r+1] - p[0][l];
		int nb = p[1][r+1] - p[1][l];
		int nc = p[2][r+1] - p[2][l];
		if(na > nb and na > nc) ans = min(ans, r+1-l);
	}

	for(int i = 0; i < int(a.size()) - 2; i++){
		int l = a[i], r = a[i+2];

		int na = p[0][r+1] - p[0][l];
		int nb = p[1][r+1] - p[1][l];
		int nc = p[2][r+1] - p[2][l];
		if(na > nb and na > nc) ans = min(ans, r+1-l);
	}

	cout << (ans == INF ? -1 : ans) << endl;

}

int32_t main(){ _
	int tt; cin >> tt;
	while(tt--) test_case();
	exit(0);
}
