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
vector<int> dp(5 * 1e5 + 10, -1);
vector<ii> v;

int solve(int i){
	if(i >= n) return 0;
	if(dp[i] != -1) return dp[i];

	int idx = upper_bound(v.begin(), v.end(), make_pair(v[i].s, INF)) - v.begin();
	return dp[i] = max(solve(i+1), solve(idx) + 1);
}

int main(){ //_
	cin >> n;
	v = vector<ii>(n);
	for(ii &i:v) cin >> i.f >> i.s;
	sort(v.begin(), v.end());

	cout << solve(0) << endl;
	exit(0);
}
