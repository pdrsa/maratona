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

// A escolhe B
ll choose(ll a, ll b, bool rep = false){
	if(rep) return choose(a+b-1, b);
	ll perm = fact(a);
	ll div  = ((fact(b) % MOD) * (fact(a-b) % MOD)) % MOD;
	div     = inv(div, MOD);
	return (perm * div) % MOD;
}


// dp[n][m] = C(n, m)

/******O(n*m)******/
int n, m;
vector<vector<ll>> dp(n+1, vector<ll>(m+1));
for(int i = 0; i < n+1; i++)
	dp[i][0] = 1;
for(int i = 1; i < n+1; i++)
	for(int j = 1; j < m+1; j++)
		dp[i][j] = dp[i-1][j-1] + dp[i-1][j];

