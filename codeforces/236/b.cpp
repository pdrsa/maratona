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
const int MAX = 1002;
int n, k;
vector<int> t;
//vector<vector<int>> dp(MAX, vector<int>(MAX,-1));

/*int solve(int i, int s){
	if(i == n) return 0;
	if(dp[i][s] != -1) return dp[i][s];
	
	int a, b;
	a = t[i]
	return dp[i][s] = min(
}*/


int main(){ _
	cin >> n >> k;
	t = vector<int>(n);
	for(int &i:t) cin >> i;
	
	ll ans = LINF;
	int ansidx;
	for(int i = 1; i <= 2000; i++){
		ll act = 0;
		int acts = i;
		for(int j = 0; j < n; j++){
			if(t[j] != acts) act++;
			acts += k;
		}
		if(act < ans){
			ans = act;
			ansidx = i;
		}
	}

	cout << ans << endl;

	int acts = ansidx;
	for(int j = 0; j < n; j++){
		if(t[j] < acts) cout << "+ " << j+1 << " " << abs(acts-t[j]) << endl;
		else if(t[j] > acts) cout << "- " << j+1 << " " << abs(acts-t[j]) << endl;

		acts += k;
	}

	exit(0);
}
