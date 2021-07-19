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
		int n; cin >> n;
		int ans = 1;
		int act = 1;
		n--;
		while(n > 0){
			act =  min(n, act+2);
			n   -= act;
			ans ++;
		}
		cout << ans << endl;
	}
	exit(0);
}
