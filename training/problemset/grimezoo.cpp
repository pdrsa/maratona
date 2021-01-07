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
string s;
int x, y;
vector<vector<int>> dp(2, vector<int> (1e5 + 2, -1));

ll solve(int i, int last){
	if(i == s.size()) return 0;
	if(last != -1 and dp[last][i] != -1) return dp[last][i];
	
	// Can't change
	if(s[i] != '?'){
		int add = 0;
		
		if(last == -1) return solve(i+1, s[i] - '0');

		if(last == 0 and s[i] == '1') add = x;
		
		if(last == 1 and s[i] == '0') add = y;
		return dp[last][i] = solve(i+1, s[i] - '0') + add;
	}

	if(last == -1) return min( solve(i+1, 0), solve(i+1, 1) );
	if(last == 0)  return dp[last][i] = min( solve(i+1, 0), solve(i+1, 1) + x);
	if(last == 1)  return dp[last][i] = min( solve(i+1, 1), solve(i+1, 0) + y);
}

int main(){ _
	cin >> s;
	cin >> x >> y;
	cout << solve(0, -1) << endl;
	exit(0);
}
