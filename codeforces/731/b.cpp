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
		char p = 'a' + (s.size() - 1);
		//cout << p << endl;
		int l = 0, r = s.size() - 1;

		bool ans = true;

		while(1){
			if(s[l] == p and l <= r) l++, p--;
			else if(s[r] == p and l <= r) r--, p--;
			else{
				if(p >= 'a') ans = false;
				break;
			}
			
			if(p < 'a') break;
		}

		cout << (ans ? "YES" : "NO") << endl;
	}
	exit(0);
}
