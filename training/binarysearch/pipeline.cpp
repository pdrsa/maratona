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

ll n, k;

bool solve(ll m){
	if(m > k) return false;

	ll up = ((k) * (k+1))/2;
	
	ll down = 0;

	if(m < k) down = ((k - m) * (k - m + 1))/2;

	return (up - down) >= n;
}

int main(){ _
	cin >> n >> k;
	k--;
	n--;

	ll l = 0, r = k + 1;
	while(l < r){
		ll m = (l+r)/2;
		if(solve(m)) r = m;
		else l = m+1;
	}

	cout << (l == (k+1) ? -1 : l) << endl;
	exit(0);
}
