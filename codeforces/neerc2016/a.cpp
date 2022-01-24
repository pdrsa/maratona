//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
// #define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int32_t main(){ _
	freopen("alex.in", "r",stdin);
	freopen("alex.out","w",stdout);
	double a, b; cin >> a >> b;
	cout << fixed << setprecision(6);
	cout << max({min(b, a/3.0), min(a, b/3.0), min(a/2.0, b/2.0)}) << endl;
	exit(0);
}
