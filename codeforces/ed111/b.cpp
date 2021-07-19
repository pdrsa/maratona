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
		int n, a, b; cin >> n >> a >> b;
		string s; cin >> s;
		
		if(b > 0){
			cout << n*a + n*b << endl;
			continue;
		}

		int r0 = 0, r1 = 0;
		for(int i = 0; i < n-1; i++){
			if(s[i] != s[i+1]){
				if(s[i] == '0') r0++;
				else r1++;
			}
		}

		if(s[n-1] == '0') r0++;
		else r1++;
		
		//cout << r0 << " " << r1 << endl;
		cout << n*a + (min(r0, r1 ) + 1) * b << endl;
	}
	exit(0);
}
