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
const int MAX = 2020;

int m, d;
string a, b, s;

ll dp[MAX][MAX][2];

ll solve(int i, int j, int k){ // K means I'm bounded to string S
	if(dp[i][j][k] != -1) return dp[i][j][k];

	if(i == s.size()) return j == 0;


	ll ret = 0;
	int bound = k ? s[i] - '0' : 9;

	for(int p = 0; p <= bound; p++){
		if(i % 2 == 1 and p != d) continue;
		if(i % 2 == 0 and p == d) continue;
		
		int nj = (j*10 + p) % m;
		
		// If it's on max and bounded
		if(k and p == bound) ret += solve(i+1, nj, 1);
		else ret += solve(i+1, nj, 0);

		ret %= MOD;
	}

	return dp[i][j][k] = ret;
}

bool check(){
	int r = 0;
	for(int i = 0; i < s.size(); i++){
		if(i % 2 == 1 and s[i] - '0' != d) return false;
		if(i % 2 == 0 and s[i] - '0' == d) return false;
		r = (r*10 + int(s[i] - '0')) % m;
	}
	return r == 0;
}

void zero(){
	for(int i = 0; i < MAX; i++) for(int j = 0; j < MAX; j++)
		for(int k = 0; k < 2; k++) dp[i][j][k] = -1;
}

int main(){ _
	cin >> m >> d >> a >> b;
	
	// Till b
	zero();
	s = b;
	ll bans = solve(0, 0, 1);
	
	// Till a
	zero();
	s = a;
	ll aans = solve(0, 0, 1);

	cout << (bans + check() + MOD - aans) % MOD << endl;
	exit(0);
}
