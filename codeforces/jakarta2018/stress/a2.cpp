//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
// #define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int dp[2010][2010];

int editDist(string str1, string str2, int m, int n){
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({dp[i][j - 1], // Insert
                               dp[i - 1][j],  // Remove
                               dp[i - 1][j - 1]}); // Replace
        }
    }

    return dp[m][n];
}

int32_t main(){ //_
	string s; cin >> s;
	int n = s.size();

	vector<string> ans(4);
	for(int i = 0; i < n; i++){
		ans[0].pb('0'), ans[1].pb('0'), ans[2].pb('1'), ans[3].pb('1');
	}
	ans[0][0] = '1', ans[2][0] = '0';
	
	for(int i = 0; i < 4; i++){
		int dist = editDist(ans[i], s, n, n);
		if(dist > n/2){
			cout << ans[i] << endl;
			exit(0);
		}
	}
	// cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
	assert(false);
	exit(0);
}
