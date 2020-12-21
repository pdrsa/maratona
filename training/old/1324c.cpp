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
	int tt; cin >> tt;
	while(tt--){
		string s; cin >> s;
		int act = 0, ans = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == 'L') act++;
			else{
				ans = max(act,ans);
				act = 0;
			}
		}
		ans = max(ans,act);

		cout << ans+1 << endl;
	}
	exit(0);
}
