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

int n;
vector<vector<int>> pd;
vector<int> d;

int solve(int i, int t){
	if(i == n) return 0;
	if(t >= 2*n + 2) return INF;
	if(pd[i][t] != -1) return pd[i][t];

	return pd[i][t] = min(abs(d[i] - t) + solve(i+1, t+1), solve(i, t+1));
}

int main(){ _
	int tt; cin >> tt;
	while(tt--){
		cin >> n;
		
		pd = vector<vector<int>> (n, vector<int>(2*n + 2, -1));

		d = vector<int>(n);
		for(int &i:d) cin >> i;
		sort(d.begin(), d.end());

		cout << solve(0,1) << endl;
	}
	exit(0);
}
