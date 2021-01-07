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

int main(){ //_
	int tt; cin >> tt;
	while(tt--){
		int n, x; cin >> n >> x;
		vector<ii> a(n);
		
		bool imp = false;
		for(auto &[i,m]: a){
			cin >> i; m = 1;
			if(i % x != 0) imp = true;
		}
		
		ll sum = 0;

		for(int j = 0; j < a.size(); j++){
			auto [i,m] = a[j];

			if(i % x == 0){
				i /= x;

				if(imp) sum += (i * (x * m));

				else a.pb({i, (x * m)});

				if(i % x != 0) imp = true;
			}
			
			else break;
		}
	
		for(auto [i, m]: a) sum += (i*m);

		cout << sum << endl;

	}
	exit(0);
}
