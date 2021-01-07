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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
int n;
vector<vector<ll>> c;
vector<vector<ll>> dp;

ll solve(int i, int r){
	if(i >= n) return 0;
	if(dp[r][i] != -1) return dp[r][i];
	vector<ll> t = c[i];
	vector<ll> b(7, -INF);
	
	// 1 of 1
	if(t[0] != 0){
		b[0] = t[0] + solve(i+1, (r+1) % 10);
		if(r == 0) b[0] += t[0];
	}
	// 2 of 1
	if(t[1] != 0){
		b[1] = t[0] + t[1] + solve(i+1, (r+2) % 10);
		if(r == 9 or r == 0) b[1] += t[0];
	}
	// 3 of 1
	if(t[2] != 0){
		b[2] = t[0] + t[1] + t[2] + solve(i+1, (r+3) % 10);
		if(r > 7 or r == 0) b[2] += t[0];
	}
	// 1 of 2
	if(t[3] != 0){
		b[3] = t[3] + solve(i+1, (r+1) % 10);
		if(r == 0) b[3] += t[3];
	}
	// 1 of 2 and 1 of 1
	if(t[3] != 0 and t[0] != 0){
		b[4] = t[3] + t[0] + solve(i+1, (r+2) % 10);
		if(r == 9 or r == 0) b[4] += max(t[3],t[0]);
	}
	// 1 of 3
	if(t[4] != 0){
		b[5] = t[4] + solve(i+1, (r+1) % 10);
		if(r == 0) b[5] += t[4];
	}
	// Play nothing
	b[6] = solve(i+1, r);

	ll ans = *max_element(b.begin(), b.end());

	return dp[r][i] = ans;
}

int main(){ _
	cin >> n;
	for(int i = 0; i < n; i++){
		int kk; cin >> kk;

		vector<ll> aux;
		ll m2 = 0, m3 = 0;
		
		// Receive
		while(kk--){
			int cost; cin >> cost;
			ll dmg; cin >> dmg;
			if(cost == 1) aux.pb(dmg);
			if(cost == 2) m2 = max(m2, dmg);
			if(cost == 3) m3 = max(m3, dmg);
		}
		
		// Reduce
		vector<ll> round(5);
		sort(aux.begin(), aux.end());
		reverse(aux.begin(), aux.end());
		for(int j = 0; j < 3; j++){
			if(aux.size() > j) round[j] = aux[j];
			else round[j] = 0;
		}
		round[3] = m2;
		round[4] = m3;
		c.pb(round);
	}
	
	dp = vector<vector<ll>> (10, vector<ll>(n, -1));
	cout << solve(0,1) << endl;

	exit(0);
}
