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
		int n, m; cin >> n >> m;
		if(m == 1) cout << n+1 << endl;
		else if(n == m) cout << 2 << endl;
		else cout << 3 << endl;
	}
	exit(0);
}
