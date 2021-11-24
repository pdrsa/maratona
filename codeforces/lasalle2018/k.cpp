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

vector<int> sum(string s){
	int a = int(s[0] - '0') + int(s[1] - '0');
	int b = int(s[2] - '0') + int(s[3] - '0');
	int c = int(s[4] - '0');
	return {a, b, c}; // Left, Right, Middle
}

int32_t main(){ //_
	int tt; cin >> tt;
	vector<string> k = {
	"11112", // 0
	"00110", // 1
	"01103", // 2
	"00113", // 3
	"10111", // 4
	"10013", // 5
	"11013", // 6
	"00111", // 7
	"11113", // 8
	"10113", // 9
	};
	
	while(tt--){
		string s; cin >> s;
		int x = int(s[0] - '0');
		int y = int(s[1] - '0');
		auto a = sum(k[x]);
		auto b = sum(k[y]);
		int ans = a[0] + a[1] + a[2] + b[0] + b[1] + b[2];
		if(x == 1) cout << ans << endl;
		else if(k[x][2] == k[y][0] and k[x][3] == k[y][1]) // Merge
			cout << ans - a[1] << endl;
		else // Don't Merge
			cout << ans << endl;
	}
	exit(0);
}
