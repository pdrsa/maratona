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
		int n; cin >> n;
		vector<int> v(n); for(int &i: v) cin >> i;
		sort(v.rbegin(), v.rend());
		
		ll a = 0, b = 0;

		for(int i = 0; i < n; i++){
			if(i % 2 == 0 and v[i] % 2 == 0) a += v[i];
			if(i % 2 == 1 and v[i] % 2 == 1) b += v[i];
		}

		if(a > b) cout << "Alice" << endl;
		if(b > a) cout << "Bob" << endl;
		if(b == a) cout << "Tie" << endl;
	}
	exit(0);
}
