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

ll isprime(ll x){
	for(int i = 2; i <= sqrt(x); i++){
		if(x % i == 0) return false;
	}
	return x != 1;
}

int main(){ _
	int n; cin >> n;
	
	while(n--){
		ll x; cin >> x;
		ll rq = int(sqrt(x));
		cout << ((rq * rq == x and isprime(rq)) ? "YES " : "NO ") << endl;
	}

	exit(0);
}
