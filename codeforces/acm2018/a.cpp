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

int main(){ _
	int tt; cin >> tt;
	while(tt--){
		int m, k; cin >> m >> k;
		vector<vector<int>> v;
		for(int i = 0; i < m; i++){
			int a, b, c; cin >> a >> b >> c;
			v.pb({a, -1, c});
			v.pb({b, 1, c});
		}
	}
	exit(0);
}
