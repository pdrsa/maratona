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
vector<int> dp;
vector<int> r;
int n, a, b, c;

int solve(int i){
	if(i == 0) return 0;
	if(i < 0) return -INF;
	if(dp[i] != -1) return dp[i];

	return dp[i] = max({solve(i-a), solve(i-b), solve(i-c)}) + 1;
}

int main(){ _
	cin >> n >> a >> b >> c;
	dp = vector<int> (n+1, -1);
	cout << solve(n) << endl;
	exit(0);
}
