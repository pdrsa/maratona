//JP - Not in Kansas Anymore
#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<ll> sq;
map<ll, ll> sqR;

int rand(int a, int b){ // Random on [a, b]
	return rand()%(b-a+1) + a;
}

vector<pair<int, int>> mv = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

bool can(int a, int b){
	return (a >= 0 and a <= 1e6 and b >= 0 and b <= 1e6);
}

void findBall(){
	int x = 0; // rand(0, 1e6);
	int y = 0; // rand(0, 1e6);
	cout << x << " " << y << endl;
	ll dist; cin >> dist;

	vector<pair<int, int>> tries;
	for(int i = 0; i < sq.size(); i++){
		if(binary_search(sq.begin(), sq.end(), dist - sq[i]))
			tries.pb({i, sqR[dist - sq[i]]});
	}

	for(auto [d1, d2]: tries){
		ll got;
		for(auto [dx, dy]: mv){
			int gx, gy;

			gx = x + d1*dx;
			gy = y + d2*dy;
			if(can(gx, gy)){
				cout << gx << " " << gy << endl;
				cin >> got; if(got == 0LL) return;
			}

			gx = x + d2*dx;
			gy = y + d1*dy;
			if(can(gx, gy)){
				cout << gx << " " << gy << endl;
				cin >> got; if(got == 0LL) return;
			}
		}
	}
}

int32_t main(){ //_
	srand((unsigned)time(0)); // Get random seed

	int n; cin >> n;
	for(ll i = 0; i <= 1e6; i++){
		sq.pb(i*i);
		sqR[i*i] = i;
	}

	while(n--) findBall();

	exit(0);
}
