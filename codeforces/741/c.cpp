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
	while(tt--){
		int n; cin >> n;
		string s; cin >> s;
		bool ans = false;
		for(int i = 0; i < (n+1)/2; i++){
			if(s[i] == '0'){
				cout << i+1 << " " << n << " ";
				cout << i+2 << " " << n << endl;
				ans = true;
				break;
			}
		}
		if(ans) continue;
		if(s[n/2] == '0'){
			cout << 1 << " " << n/2 + 1<< " ";
			cout << 1 << " " << n/2 << endl;
		}
		else{
			cout << 2 << " " << n/2 + 1<< " ";
			cout << 1 << " " << n/2 << endl;
		}
	}
	exit(0);
}
