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
		ll sum = 0;
		vector<int> a(n);
		for(int &i:a){
			cin >> i; sum += i;
		}

		ll ans = INF;
		for(int t = n; t >= 1; t--){
			if(sum % t == 0){
				ll trye = (sum/t);
				bool can = true;
				ll act = 0;
				for(int i = 0; i < n; i++){
					if(act + a[i] == trye){
						act = 0; continue;
					}
					else if(act + a[i] > trye) can = false;

					act += a[i];
				}
				if(act != 0) can = false;

				if(can){
					ans = (n-t); break;
				}
			}
		}

		cout << ans << endl;

	}
	exit(0);
}
