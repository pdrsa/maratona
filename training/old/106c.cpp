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


int pd[1005][15];
int cp, dp;
int a[15];
int b[15];
int c[15];
int d[15];

int solve(int n, int m){
	if (n == 0) return 0;
	if (m == 0) return (n/cp) * dp;
	if (pd[n][m] != -1) return pd[n][m];

	int ans = solve(n, m-1);

	for (int i = 1; n - i*cp >= 0; i++){
		ans = max(ans, i*dp + solve(n - i*cp, m-1));
	}

	for (int i = 1; a[m] - i*b[m] >= 0 and n - i*c[m] >= 0; i++){
		ans = max(ans, i*d[m] + solve(n - i*c[m],m-1));
	}
	
	return pd[n][m] = ans;
}

int main(){ 
	int N, M; cin >> N >> M >> cp >> dp;
	for (int i = 1; i <= M; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
	memset(pd, -1, sizeof (pd));
	
	cout << solve(N,M) << endl;

	exit(0);
}
