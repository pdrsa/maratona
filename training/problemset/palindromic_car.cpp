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
const int MAX = 5e3 + 50;

int dp[MAX][MAX];

int main(){ _
	string s; cin >> s;
	int n = s.size();
	
	for(int j = 0; j <= n; j++) dp[0][j] = dp[1][j] = 1;
	vector<ll> ans(n+1);
	for(int i = 2; i <= n; i++){
		for(int j = 0; j <= (n - i); j++){
			if(dp[i-2][j+1] and s[j] == s[j+i-1]) dp[i][j] = 1;
			if(dp[i][j]) dp[i][j] += dp[(i/2)][j];
			
			ans[dp[i][j]]++;
		}
	}

	ans[1] += n;
	for(int j = n; j >= 1; j--) ans[j-1] += ans[j];
	for(int i = 1; i <= n; i++) cout << ans[i] << " ";
	cout << endl;
	exit(0);
}
