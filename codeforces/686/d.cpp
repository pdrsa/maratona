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
	int tt; cin >> tt;
	while(tt--){
		ll n; cin >> n;
		ll aux = n;
		map<ll, int> d;
		ll ans = 0, ansd;

		while(aux % 2 == 0){
			aux /= 2;
			d[2]++;
			if(d[2] > ans){
				ansd = 2;
				ans = d[2];
			}
		}

		for(ll i = 3; i * i <= n; i += 2){
			while(aux % i == 0){
				//cout << aux << " div " << i << endl;
				aux /= i;
				d[i]++;
				if(d[i] > ans){
					ansd = i;
					ans = d[i];
				}
			}
		}
		
		//cout << "ans " << ans << " and ansd " << ansd << endl;
		cout << max(ans,1LL) << endl;
		for(int i = 0; i < ans-1; i++){
			n /= ansd;
			cout << ansd << " ";
		}

		cout << n;

		cout << endl;
	}
	exit(0);
}
