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

vector<int> dp;

int main(){ _
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		int ans = 0;
		vector<string> stories(n); for(string &ss: stories) cin >> ss;

		for(int big = 0; big < 5; big++){
			
			vector<int> p;
			for(string s: stories){
				int bc = 0;
				for(char c: s){
					if(c - 'a' == big) bc++;
					else bc--;
				}
				p.pb(bc);
			}
			sort(p.rbegin(), p.rend());
			int bc = 0, nS = 0;
			for(int i: p){
				bc += i;
				if(bc > 0) nS++;
				else break;
			}
			ans = max(ans, nS);
		}

		cout << ans << endl;
	}
	exit(0);
}
