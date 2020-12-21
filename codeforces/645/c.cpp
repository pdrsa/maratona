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
	int t; cin >> t;
	while(t--){
		ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		cout << (y2 - y1) * (x2 - x1) + 1 << endl;
	}
	exit(0);
}
