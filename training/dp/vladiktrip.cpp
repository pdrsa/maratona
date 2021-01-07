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
const int MAX = 5e3+2;

int n;
vector<int> e(MAX);
vector<int> b(MAX, -1);
vector<ll> dp(MAX, -1);
vector<int> v;

ll solve(int i){
	if(i >= n) return 0;
	if(dp[i] != -1) return dp[i];
	if(b[v[i]] < i) return dp[i] = solve(i+1);
	
	ll act = 0;
	set<int> seg;
	int j = i;

	int endpoint = e[v[i]];
	for(; j <= endpoint; j++){
		if(b[v[j]] < j and !seg.count(v[j])) return dp[i] = solve(i+1);

		endpoint = max(endpoint, e[v[j]]);
		seg.insert(v[j]);
	}

	for(int aux: seg) act ^= aux;

	return dp[i] = max(solve(i+1), solve(j) + act);
}

int main(){ _
	cin >> n;
	v = vector<int>(n);
	
	for(int i = 0; i < n; i++){
		cin >> v[i];
		if(b[v[i]] == -1) b[v[i]] = i;
		e[v[i]] = i;
	}
	cout << solve(0) << endl;
	
	exit(0);
}
