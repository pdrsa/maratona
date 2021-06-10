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
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		ll p1 = 0, p2 = 0;
		ll s = 2;
		for(int i = 0; i < n/2 - 1; i++){
			p1 += s;
			s *= 2;
		}
		for(int i = n/2 - 1; i < n-1; i++){
			p2 += s;
			s *= 2;
		}
		p1 += s;
		cout << p1 - p2 << endl;
	}
	exit(0);
}
