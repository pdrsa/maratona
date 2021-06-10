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
	ll n, b, p; cin >> n >> b >> p;
	ll bot = 0;
	p *= n;
	while(n > 1){
		ll k = 1;
		while(k * 2 <= n) k *= 2;
		bot += k * b + (k/2);
		n   -= (k/2);
	}
	cout << bot << " " << p << endl;
	exit(0);
}
