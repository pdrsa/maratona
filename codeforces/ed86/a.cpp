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
	ll x, y, a, b; cin >> x >> y >> a >> b;
	if (2 * a < b) cout << (x + y) * a << endl;
	else{
		cout << abs(x-y)*a + ((x+y - abs(x-y))/2) * b << endl;
	}
	}

	exit(0);
}
