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
vector<int> dp(4010);
int n, a, b, c;

ll solve(int x){
	if(x < 0) return -INF;
	if(x == 0) return 0;
	return dp[x] = max({solve(x-a), solve(x-b), solve(x-c)}) + 1;
}

int main(){ _
	cin >> n >> a >> b >> c;
	cout << solve(n) << endl;
	exit(0);
}
