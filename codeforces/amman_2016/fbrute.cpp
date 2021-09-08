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
		vector<string> S;
		string s; cin >> s;
		int n = s.size();
		for(int i = 0; i < n; i++){
			for(int j = i; j < n; j++){
				char a = s[i], c = s[j];
				string now = s;
				for(int k = 0; k < n; k++){
					if(now[k] == a) now[k] = c;
					else if(now[k] == c) now[k] = a;
				}
				S.pb(now);
			}
		}

		sort(S.begin(), S.end());
		cout << S[0] << endl;
	}
	exit(0);
}
