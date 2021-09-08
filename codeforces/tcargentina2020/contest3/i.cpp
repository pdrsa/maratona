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
const ll MOD = 1e9+7;

int main(){ _
	int n; cin >> n;
	ll a = 0, b = 0; // A -> % 2 == 1, B -> %2 == 0
	for(int i = 0; i < n; i++){
		if(i % 2) a += b + 1;
		else b += a + 1;
		a %= MOD, b %= MOD;
	}
	cout << (a+b) % MOD << endl;
	exit(0);
}
