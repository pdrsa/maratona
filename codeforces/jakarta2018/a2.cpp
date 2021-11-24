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

int editDist(string str1, string str2, int m, int n)
{
    // Create a table to store results of subproblems
    int dp[m + 1][n + 1];

    // Fill d[][] in bottom up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            // If first string is empty, only option is to
            // insert all characters of second string
            if (i == 0)
                dp[i][j] = j; // Min. operations = j

            // If second string is empty, only option is to
            // remove all characters of second string
            else if (j == 0)
                dp[i][j] = i; // Min. operations = i

            // If last characters are same, ignore last char
            // and recur for remaining string
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            // If the last character is different, consider
            // all possibilities and find the minimum
            else
                dp[i][j]
                    = 1
                      + min({dp[i][j - 1], // Insert
                            dp[i - 1][j], // Remove
                            dp[i - 1][j - 1]}); // Replace
        }
    }

    return dp[m][n];
}

int32_t main(){ //_
	string s; cin >> s;
	int n1 = 0, n0 = 0;
	for(char c: s)
		if(c == '1') n1++;
		else n0++;
		
	string ans;
	char print;
	if(n0 != n1){
		if(n0 > n1) print = '1';
		else print = '0';
		for(char c: s) ans.pb(print);
	} else for(char c: s) ans.pb('1');

	for(int i = 0; i < ans.size(); i++){
		int n = s.size();
		string ans2 = ans;
		if(ans2[i] == '1') ans2[i] = '0';
		if(ans2[i] == '0') ans2[i] = '1';
		int dist = editDist(s, ans2, n, n);
		if(dist > n/2){
			cout << ans2 << endl;
			exit(0);
		}
	}

	for(char &c: ans) c = '0';
	for(int i = 0; i < ans.size(); i++){
		int n = s.size();
		string ans2 = ans;
		if(ans2[i] == '1') ans2[i] = '0';
		if(ans2[i] == '0') ans2[i] = '1';
		int dist = editDist(s, ans2, n, n);
		if(dist > n/2){
			cout << ans2 << endl;
			exit(0);
		}
	}
	assert(false);
	exit(0);
}
