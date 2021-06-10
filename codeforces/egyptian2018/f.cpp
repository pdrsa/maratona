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
	// #warning FILE IN
	freopen("mosalah.in", "r", stdin);
	int tt; cin >> tt;
	while(tt--){
		int n, m, x, y; cin >> n >> m >> x >> y;
		if(n <= m / (x+y)) cout << 0 << endl;
		else if (y == 0) cout << -1 << endl;
		else cout << (n * (x+y)) - m << endl;
	}
	exit(0);
}
