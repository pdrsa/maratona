//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> iill;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		string ans = "2020";
		string s; cin >> s;

		int maxp = 0, maxs = 0;

		for(int j = 0; j < 4; j++){
			if(s[j] == ans[j]) maxp = j+1;
			else break;
		}
		
		for(int j = 0; j < 4; j++){
			if(s[n-j-1] == ans[3-j]) maxs = j+1;
			else break;
		}

		if(maxs + maxp >= 4) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	exit(0);
}
