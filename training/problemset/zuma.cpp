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

int dp[510][510];
int c[510];

int n;

int solve(int i, int j){
	if(i == j) return 1;
	if(i > j) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	
	int ans = 1 + solve(i+1, j);
	if(c[i+1] == c[i]) ans = min(ans, 1 + solve(i+2, j));

	for(int k = i+2; k <= j; k++)
		if(c[k] == c[i]) ans = min(solve(i+1,k-1) + solve(k+1, j), ans);

	return dp[i][j] = ans;
}

int main(){ _
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> c[i];
		for(int j = 0; j < n; j++) dp[i][j] = -1;
	}
	cout << solve(0, n-1) << endl;
	exit(0);
}
