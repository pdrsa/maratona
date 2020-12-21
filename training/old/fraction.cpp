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
	ll a, b, c, d; cin >> a >> b >> c >> d;
	ll dv = b * d;
	a *= d; c *= b;
	a += c;
	b = __gcd(a, dv);
	cout << a / b << " " << dv / b << endl;
	exit(0);
}
