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
const int MAX = 1e4+5;

int dp[101][MAX];
vector<vector<int>> it;
int n, m;

int solve(int s, int k){
	if(s == n) return 0;
	if(k == 0) return 0;
	if(dp[s][k] != -1) return dp[s][k];
	int maxi = 0;
	for(int i = 0; i < it[s].size() and i <= k; i++){
		maxi = max(solve(s+1, k-i) + it[s][i], maxi);
	}
	return dp[s][k] = maxi;
}

int main(){ _
	cin >> n >> m;
	it = vector<vector<int>>(n);
	
	for(int s = 0; s < n; s++){
		int mm; cin >> mm;
		vector<int> a(mm); for(int &i: a) cin >> i;
		vector<int> p(mm+1);
		for(int i = 1; i <= mm; i++) p[i] = p[i-1] + a[i-1];
		it[s].pb(0);
		for(int c = 1; c <= mm; c++){
			int ans = 0;
			int l = c, r = 0;
			while(l >= 0){
				int act = p[l] + (p[mm] - p[mm-r]);
				ans = max(ans,act);
				l--; r++;
			}
			it[s].pb(ans);
		}
	}
	
	/*
	for(auto a:it){
		for(auto u: a) cout << u << " ";
		cout << endl;
	}
	*/

	memset(dp, -1, sizeof dp);
	cout << solve(0,m) << endl;
	exit(0);
}
