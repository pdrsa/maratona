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

int32_t main(){ _
	int tt; cin >> tt;
	for(int t = 0; t < tt; t++){
		int n; cin >> n;
		string s; cin >> s;
		int ans = 0;
		char act = '@';
		for(int i = 0; i < n; i++){
			if(s[i] == 'F') continue;
			if(s[i] != act){
				if(act != '@') ans++;
				act = s[i];
			}
		}
		cout << "Case #" << t+1 << ": " << ans << endl;
	}
	exit(0);
}
