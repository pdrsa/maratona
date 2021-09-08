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
const int MAX = 2e5;

map<ii, int> dp;

vector<int> v;

int solve(int i, int sum){
	if(sum == 0) return 1;
	if(i >= v.size()) return 0;

	ii memo = {i, sum};
	if(dp.count(memo)) return dp[memo];

	bool a = solve(i+1, sum);
	bool b = solve(i+1, sum - v[i]);
	bool c = solve(i+1, sum + v[i]);

	if(a or b or c) return dp[memo] = 1;
	else return dp[memo] = 0;
}

bool check(int t, vector<int> sum){
	dp.clear();
	v = sum;
	return bool(solve(0, t));
}

int main(){ _
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		vector<int> dif(n); for(int &i: dif){
			cin >> i;
			if(i < 0) i = -i;
		}
			
		bool ans = false;
		for(int i = 0; i < n; i++){
			vector<int> sum;
			for(int j = 0; j < n; j++) if(j != i) sum.pb(dif[j]);
			if(check(dif[i], sum)){
				ans = true;
				break;
			}
		}

		cout << (ans ? "YES" : "NO") << endl;	
	}
	exit(0);
}
