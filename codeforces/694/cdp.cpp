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

//vector<vector
vector<ll> f, p;
int n, m;

ll solve(int i, int j){
	if(i >= n) return 0;
	if(j >= m) return f[i];
	if(pd[i][j]
}

int main(){ _
	cin >> n >> m;
	pd = f = vector<ll>
	l> (n, -1);
	p = vector<ll> (m);
	for(ll &i: f) cin >> i;
	for(ll &i: p) cin >> i;
	
	cout << solve(0, 0) << endl;
	exit(0);
}
