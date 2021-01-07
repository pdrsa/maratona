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

vector<int> a;
vector<vector<int>> dp;
int n, m;

bool solve(int i, int r){
	// Fix neg values
	if(r < 0) r = (m + (r%m)) % m;
	
	// Stop recursion
	if(i < 0) return false;
	
	// Memorization
	if(dp[i][r] != -1) return dp[i][r];

	// Can
	if(a[i] == r or (solve(i-1, r) > 0) or (solve(i-1, (r-a[i])) > 0))
		return dp[i][r] = 1;
	
	// Cannot
	else
		return dp[i][r] = 0;
}

int main(){ _
	cin >> n >> m;

	if(n > m){
		cout << "YES" << endl;
		exit(0);
	}
	
	// Declare
	dp = vector<vector<int>> (n, vector<int> (m, -1));
	a  = vector<int> (n);

	for(int &i: a){
		cin >> i; i %= m;
	}
	
	cout << (solve(n-1, 0) ? "YES" : "NO" ) << endl;

	exit(0);
}
