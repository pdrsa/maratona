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
const ll MAX = 1e12;

vector<pair<int,ii>> o;
int n, ma;

bool go(ll m, int x, int i){
	if(m < 0 or x < 1 or x > n) return false;
	if(i == ma) return true;

	int mv;
	int l = o[i].s.f;
	int r = o[i].s.s;
	if(o[i].f == 1){
		// Go to right
		mv = max((r+1) - x, 0);
		if(go(m - mv, x + mv, i+1)) return true;

		// Go to left
		mv = max(x - (l-1), 0);
		if(go(m - mv, x - mv, i+1)) return true;
	}

	else{
		// Still
		if(l <= x and r >= x)
			if(go(m, x, i+1)) return true;

		// Go to right
		if(l > x and r > x){
			mv = l - x;
			if(go(m - mv, x + mv, i+1)) return true;
		}

		// Go to left
		if(l < x and r < x){
			mv = x - r;
			if(go(m - mv, x - mv, i+1)) return true;
		}
	}

	return false;
}

int main(){ _
	int x; cin >> n >> ma >> x;
	o = vector<pair<int,ii>>(ma);
	
	for(int i = 0; i < ma ; i++) cin >> o[i].f >> o[i].s.f >> o[i].s.s;

	ll l = 0, r = MAX;

	while(l < r){
		ll mid = (l+r)/2;
		if(go(mid, x, 0)) r = mid;
		else l = mid+1;
	}
	
	cout << (l == MAX ? -1 : l) << endl;

	exit(0);
}
