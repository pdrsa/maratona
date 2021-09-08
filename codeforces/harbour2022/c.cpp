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
		int ans = 10;

		int t1g = 0, t2g = 0;
		// T1 Good
		for(int i = 0; i < 10; i++){
			if(i % 2 == 0){
				if(s[i] == '1' or s[i] == '?') t1g++;
			}
			else if(s[i] == '1') t2g++;

			if(t1g > t2g + ((5 - (i+1)/2))){
				ans = min(ans, i+1);
				break;
			}
		}

		t1g = 0, t2g = 0;
		//T2 Good
		for(int i = 0; i < 10; i++){
			if(i % 2 == 0){
				if(s[i] == '1') t1g++;
			}
			else if(s[i] == '1' or s[i] == '?') t2g++;

			if(t2g > t1g + ((5 - (i+2)/2))){
				ans = min(ans, i+1);
				break;
			}
		}
		
		cout << ans << endl;
	}
	exit(0);
}
