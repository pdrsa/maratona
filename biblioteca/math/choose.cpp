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
const int MOD = 1e9+7;
const int MAX = 1e7;

ll fat[MAX];

ll inv(ll a, ll b) {
	return a > 1 ? b - inv(b%a, a)*b/a : 1;
}

ll fact(ll n){
	if(n == 0) return 1LL;
	if(fat[n] != -1) return fat[n];
	else return fat[n] = ((n * fact(n-1)) % MOD);
}

// A escolhe B
ll choose(ll a, ll b, rep = false){
	if(rep) return choose(a+b-1, b);
	ll perm = fact(a);
	ll div  = ((fact(b) % MOD) * (fact(a-b) % MOD)) % MOD;
	div     = inv(div, MOD);
	return (perm * div) % MOD;
}

int main(){ _
	for(int i = 0; i < MAX; i++) fat[i] = -1;

	exit(0);
}
