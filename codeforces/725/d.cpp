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
const int MAX = 1e5;

int main(){ _
	int tt; cin >> tt;
	while(tt--){
		//vector<bool> da(MAX);
		int a, b, k; cin >> a >> b >> k;
		int nd = 0;
		
		if(k == 1){
			if(a != b and (a % b == 0 or b % a == 0)) cout << "YES" << endl;
			else cout << "NO" << endl;

			continue;
		}

		//bool common = false;

		while(a % 2 == 0){
			a /= 2;
			nd++;
			//da[2] = true;
		}

		while(b % 2 == 0){
			b /= 2;
			nd++;
			//if(da[2]) common = true;
		}

		for(int i = 3; i * i <= a; i += 2){
			while(a % i == 0){
				
				a /= i;
				nd++;
				//da[i] = true;
			}
		}

		if(a > 2){
			nd++;
			//da[a] = true;
		}

		for(int i = 3; i * i <= b; i++){
			while(b % i == 0){
				b /= i;
				nd++;
				//if(da[i]) common = true;
			}
		}

		if(b > 2){
			nd++;
			//if(da[b]) common = true;
		}

		//cout << nd << endl;
		if(k <= nd) cout << "YES" << endl;
		else cout << "NO" << endl;
	
	}
	exit(0);
}
