#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;


const ll MOD = 100000000;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int kf, kh;

ll dp[101][101][11][11];

ll solve(int f, int h, int cf, int ch){
	if (dp[f][h][cf][ch] != -1) return dp[f][h][cf][ch];

	if (f+h == 0) return 1;

	ll ans1 = 0, ans2 = 0;

	if (f > 0 and cf < kf) ans1 = solve(f-1,h,cf+1,0)%MOD;
	if (h > 0 and ch < kh) ans2 = solve(f,h-1,0,ch+1)%MOD;

	return dp[f][h][cf][ch] = (ans1 + ans2) % MOD;
}

int main(){
    int f, h;
	memset(dp, -1, sizeof dp);
	cin >> f >> h >> kf >> kh;
	
    cout << solve(f,h,0,0) % MOD << endl;

    return 0;
}
