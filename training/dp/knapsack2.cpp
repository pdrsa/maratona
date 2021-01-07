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

const int MAX = 1e5+3;
vector<int> v(101);
vector<int> w(101);
int n, W;

int main(){ _
	vector<vector<int>> dp(101, vector<int>(MAX, INF)); 
	cin >> n >> W;
	int sum = 0;
	
	for(int i = 0; i < n; i++){
		cin >> w[i] >> v[i];
		sum += v[i];
	}
	
	dp[0][0] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= sum; j++){
			dp[i][j] = min(dp[i][j], dp[i-1][j]);
			if(j >= v[i-1]) dp[i][j] = min(dp[i][j], dp[i-1][j-v[i-1]] + w[i-1]);
		}
	}
	int ans = 0;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= sum; j++){
			//cout << i << " " << j << " = " << dp[i][j] << endl;
			if(dp[i][j] <= W) ans = max(ans, j);
		}
	}

	cout << ans << endl;
	exit(0);
}
