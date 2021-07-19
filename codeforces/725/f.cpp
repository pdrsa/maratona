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

ll countDivisibles(ll A, ll B, ll M){
   
    // Add 1 explicitly as A is divisible by M
    if (A % M == 0)
        return (B / M) - (A / M) + 1;
 
    // A is not divisible by M
    return (B / M) - (A / M);
}

int main(){ _
	int tt; cin >> tt;
	while(tt--){
		ll ans = 0;
		ll l, r; cin >> l >> r;
		ll step = 1;
		//int p = 1;
		while(step <= (1e9 + 10)){
			ans += countDivisibles(l+1, r, step);
			step *= 10;
		}

		cout << ans << endl;
	}
	exit(0);
}
