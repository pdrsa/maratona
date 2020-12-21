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

int memo[4040];

int a, b, c;

int ans(int n){
	if (n < 0) return -INF;
	if (n == 0) return 0;
	if(memo[n] != -1) return memo[n];
	return memo[n] = 1 + max(ans(n-a), max(ans(n-b), ans(n-c)));
}

int main(){ _
	int n;
	cin >> n >> a >> b >> c;
	
	memset(memo, -1, sizeof memo);
	cout << ans(n) << endl;
	
	exit(0);
}
