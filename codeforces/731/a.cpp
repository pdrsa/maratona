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
int main(){ _
	int tt; cin >> tt;
	while(tt--){
		int ax, ay, bx, by, fx, fy;
		cin >> ax >> ay >> bx >> by >> fx >> fy;
		int d = abs(ax-bx)+abs(ay-by);

		if(ax == bx and fx == ax) if(min({ay, by, fy}) != fy and max({ay, by, fy}) != fy) d += 2;
		if(ay == by and fy == ay) if(min({ax, bx, fx}) != fx and max({ax, bx, fx}) != fx) d += 2;
		
		cout << d << endl;
	}
	exit(0);
}
