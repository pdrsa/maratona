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

int n, m;
vector<vector<ll>> bs; // Best of shelves
vector<vector<ll>> dp;

ll solve(int si, int r){
	if(r < 0) return -LINF;
	if(r == 0 or si == n) return 0;
	if(dp[si][r] != -1) return dp[si][r];

	ll best = 0;
	for(int i = 0; i < bs[si].size(); i++)
		best = max(best, solve(si + 1, r-i) + bs[si][i]);

	return dp[si][r] = best;
}


vector<int> s;
int dpaux[110][110][110];

int solves(int l, int r, int k){
	int& memo = dpaux[l][r][k];

	if(k == 1){
		return max(s[l], s[r]);
	}

	if(memo != -1) return memo;
	
	return memo = max(solves(l+1, r, k-1) + s[l], solves(l, r-1, k-1) + s[r]);
}

int main(){ //_
	cin >> n >> m;
	bs.resize(n);

	// Precalculating best for shelves
	for(int i = 0; i < n; i++){
		int nit; cin >> nit;
		s.resize(nit);
		for(int &it: s) cin >> it;
		

		// Zerando
		for(int a = 0; a < 110; a++)
			for(int j = 0; j < 110; j++)
				for(int k = 0; k < 110; k++)
					dpaux[a][j][k] = -1;
		
		bs[i].assign(nit + 1, 0);
		for(int it = 1; it <= nit; it++){
			bs[i][it] = solves(0, nit-1, it);
		}
	}

	dp.assign(n, vector<ll> (m + 10, -1));
	cout << solve(0, m) << endl;
	exit(0);
}
