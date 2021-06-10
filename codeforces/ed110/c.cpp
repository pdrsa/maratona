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
		int li;
		int lw = -1;
		ll ans  =  ll(s.size()) * ll((s.size() + 1LL)) / 2LL;
		char last = '@';

		for(int i = 0; i < s.size(); i++){
			if(s[i] != '?'){

				if(last == '@'){
					li   = i;
					last = s[i];
					continue;
				}
				
				int mid = (i - li - 1);

				if((s[i] == last and mid % 2 == 0)
				or (s[i] != last and mid % 2 == 1)){
					ans -= ((li-lw) * (s.size() - i));
					//cout << i << " -> " << (li-lw) << "*" << s.size() - i << endl;
					lw = li;
				}
				
				li   = i;
				last = s[i];
			}
		}

		cout << ans << endl;
	}
	exit(0);
}
