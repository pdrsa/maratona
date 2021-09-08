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
		string s, t; cin >> s >> t;
		bool ok = false;
		for(int i = 0; i < s.size(); i++){
			for(int j = 0; i+j < s.size() and j < t.size(); j++){
				int p = i + j - 1;
				int c = t.size() - (j+1);
				if(p - (c-1) < 0) continue;
				
				// Forward
				string ans = s.substr(i, j+1);

				// Back
				for(int k = 0; k < c; k++){
					ans.pb(s[p]);
					p--;
				}
				
				if(ans == t){
					ok = true;
					break;
				}
			}
		}

		cout << (ok ? "YES" : "NO") << endl;
	}	
	exit(0);
}
