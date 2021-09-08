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
		string os = s;
		int n = s.size();
		sort(os.begin(), os.end());
		
		string su, osu;
		osu.pb(os[0]);

		set<char> oc;
		for(int i = 0; i < s.size(); i++) {
			if(!oc.count(s[i])){
				su.pb(s[i]);
				oc.insert(s[i]);
			}
		}
		for(int i = 1; i < os.size(); i++) if(os[i] != os[i-1]) osu.pb(os[i]); 

		/*
		cout << endl;
		cout << su << endl;
		cout << osu << endl;
		cout << endl;
		*/

		char a = '$', c = '$';
		for(int i = 0; i < osu.size(); i++){
			if(su[i] != osu[i]){
				a = osu[i], c = su[i]; break;
			}
		}

		for(int i = 0; i < n; i++){
			if(s[i] == a) s[i] = c;
			else if(s[i] == c) s[i] = a;
		}

		cout << s << endl;
	}
	exit(0);
}
