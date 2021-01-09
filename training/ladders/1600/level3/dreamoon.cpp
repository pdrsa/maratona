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
vector<vector<double>> dp(11, vector<double> (11, -1));

double solve(int x, int t){
	if(x > t or t < 0 or x < 0)  return 0;
	if(x == 0 and t == 0) return 1;
	if(t == 1 and x == 1) return 0.5;
	if(dp[x][t] != -1) return dp[x][t];

	return dp[x][t] = 0.5 * solve(x, t-1) + 0.5 * solve(x-1, t-1);
}

int main(){ _
	string a, b; cin >> a >> b;
	int ob = 0, st = 0, m  = 0;

	for(auto u: a){
		if(u == '-') ob--;
		else ob++;
	}

	for(auto u: b){
		if(u == '-') st--;
		if(u == '+') st++;
		if(u == '?') m++;
	}
	
	if(abs(ob-st) % 2 != m % 2 or abs(ob-st) > m){
		cout << 0 << endl;
		exit(0);
	}

	// N of 1s
	int n1 = (ob - st) + (m - (ob-st))/2;
	
	cout << setprecision(18) << solve(n1, m) << endl;

	exit(0);
}
