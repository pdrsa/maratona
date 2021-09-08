//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

// #define int ll
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> iill;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool vowel(char c){
	return c == 'A' or c == 'E'
	or c == 'I' or c == 'O' or c == 'U';
}

int32_t main(){ _
	int ttt; cin >> ttt;
	for(int tt = 1; tt <= ttt; tt++){
		string s; cin >> s;
		int ans = INF;
		for(int i = 0; i < 26; i++){
			char now = 'A' + i;
			int t = 0;
			for(char c: s) if(c != now)
				t += 2 - (vowel(now) != vowel(c));
			ans = min(ans, t);
		}
		cout << "Case #" << tt << ": " << ans << endl;
	}
	exit(0);
}
