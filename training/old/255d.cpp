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

ll n, x, y, c;

ll calcC(ll dis1, ll dis2, ll m){
	//cout << "Distance -> " << dis1 << " " << dis2 << endl;
	ll hm = max(0LL, m - (dis1 + dis2));
	return (hm*hm + hm)/2;
}

ll calcB(ll dis, ll m){
	ll hm = max(0LL, m-dis);
	return hm*hm;
}

bool solve(ll m){
	ll ar = 0, dis;
	//cout << "M = " << m << endl;
	ar += ((m*m)-m) * 2 + 1;
	//cout << "Total area = " << ar << endl;
	ar -= calcB(x, m); ar -= calcB(n-x+1, m);
	ar -= calcB(y, m); ar -= calcB(n-y+1, m);
	//cout << "Area after removing borders = " << ar << endl;

	ar += calcC(x, y, m); ar += calcC(n-x+1, y, m);
	ar += calcC(x, n-y+1, m); ar += calcC(n-x+1, n-y+1, m);
	//cout << "Area after adding corners again = " << ar << endl;

	if(ar >= c) return true;
	else return false;
}

int main(){ _
	cin >> n >> x >> y >> c;
	ll l = 1, r = 2 * n;
	while(l < r){
		ll m = (l+r)/2;
		if(solve(m)) r = m;
		else l = m+1;
	}
	cout << l-1 << endl;
	exit(0);
}
