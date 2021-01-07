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
vector<int> t;
vector<vector<int>> dp(3, vector<int> (2e5+2, -1));
int n;

int solve(int r, int i){
	if(i == n) return 0;
	if(dp[r][i] != -1) return dp[r][i];
	
	int a = solve((r+t[i]) % 3, i+1);
	int b = solve(0, i+1) + ( (r+t[i]) % 3 == 0 ? 1 : 0);

	return dp[r][i] = max(a,b);
}

int main(){ _
	string s; cin >> s;
	n = s.size();
	t = vector<int>(s.size());
	for(int i = 0; i < n; i++) t[i] = (s[i] - '0') % 3;
	
	cout << solve(0, 0) << endl;
	exit(0);
}
