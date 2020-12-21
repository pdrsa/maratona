#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		int n1 = 0, n0 = 0;
		int act = 0;

		int ans = INF;
		for(int a = 0; a <= s.size(); a++){
			act = 0;
			n1 = 0; n0 = 0;
			for(int i = 0; i < a; i++){
				if(s[i] == '1') n1++;
				else n0++;
			}
			act += min(n1, n0);
		
			n1 = 0, n0 = 0;
			for(int i = a; i < s.size(); i++){
				if(s[i] == '1') n1++;
				else n0++;
			}
			act += min(n1,n0);

			ans = min(act, ans);
		}

		cout << ans << endl;
	}
	exit(0);
}
