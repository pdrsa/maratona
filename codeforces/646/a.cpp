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
	int t; cin >> t;
	while(t--){
		int n, x; cin >> n >> x;
		int od = 0, ev = 0;
		int aux;
		for(int i = 0; i < n; i++){
			cin >> aux;
			if(aux % 2 == 0) ev++;
			else od++;
		}

	
		if(x % 2 == 0){
			if(od == 0 or ev == 0){
				cout << "No" << endl;
				continue;
			}
		}

		if(x == n){
			if(od % 2 == 0){
				cout << "No" << endl;
			}
			else{
				cout << "Yes" << endl;
			}
		}
		else{
			if(od >= 1){
				cout << "Yes" << endl;
			}
			else{
				cout << "No" << endl;
			}
		}
		
	}
	exit(0);
}
