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
		string s; cin >> s;

		for(int i = 1; i < s.size(); i++){
			if(i > 1 and s[i] == s[i-2]) s[i] = '#';
			if(s[i] == s[i-1]) s[i] = '#';
		}
		
		int ans = 0;
		
		for(char c: s) if(c == '#') ans++;

		cout << ans << endl;
	}
	exit(0);
}
