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
vector<int> st;
int n;

int solve(int i){
	if(i >= n-1) return 0;
	if(dp[i] != -1) return dp[i];
	if(i == n-2) return abs(st[i] - st[i+1]);
	
	return dp[i] = min(solve(i+1) + abs(st[i] - st[i+1]), solve(i+2) + abs(st[i] - st[i+2]));
}

int main(){ _
	cin >> n;
	st = vector<int>(n); dp = vector<int>(n, -1);
	for(int &i:st) cin >> i;
	cout << solve(0) << endl;
	exit(0);
}
