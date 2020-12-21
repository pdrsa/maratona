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

int main(){ _
	ll n, m; cin >> n >> m;
	
	ll l = 1, r = 1e12;
	
	while(l < r){
		ll mid = (l+r)/2;
		ll aux = 1;
		for(int i = 0; i < n; i++) aux *= mid;
		if(mid >= m) r = mid;
		else l = mid+1;
	}

	cout << l << endl;

	exit(0);
}
