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
const int MAX = 3e3+2;

int dp[MAX][MAX];
string s, t;

int solve(int i, int j){
	if(i >= s.size() or j >= t.size()) return 0;
	if(dp[i][j] != -1) return dp[i][j];

	int a = solve(i+1, j+1);
	int b = solve(i+1, j);
	int c = solve(i, j+1);

	if(s[i] == t[j]) return dp[i][j] = max({a + 1, b, c});
	else return dp[i][j] = max({a,b,c});
}

vector<char> rec(int i, int j){
	vector<char> ans;
	while(i < s.size() and j < t.size()){
		int a = solve(i+1, j+1);
		int b = solve(i+1, j);
		int c = solve(i, j+1);
		int maxi = max({a,b,c});
	
		if(s[i] == t[j] and a+1 >= maxi){
			ans.pb(s[i]); i++; j++;
		}
		else{
			if(maxi == b) i++;
			else j++;
		}
	}

	return ans;
}

int main(){ _
	cin >> s >> t;
	memset(dp, -1, sizeof dp);
	
	for(char i: rec(0,0)) cout << i;
	cout << endl;

	exit(0);
}
