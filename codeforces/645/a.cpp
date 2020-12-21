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

int solve(int x, int y){
	if(x == 0 or y == 0) return 0;
	if(x == 1 and y == 1) return 1;
	return min(x,y) * (max(x,y)/2) + solve((max(x,y) % 2), min(x,y));
}

int main(){ _
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		cout << solve(n, m) << endl;
	}
	exit(0);
}
