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
		int n, m; cin >> n >> m;
		vector<pair<bool,bool>> a(1002, {false, false});
		int aux;
		for(int i = 0; i < n; i++){
			cin >> aux;
			a[aux].f = true;
		}

		for(int i = 0; i < m; i++){
			cin >> aux;
			a[aux].s = true;
		}
		
		int i;
		for(i = 0; i < 1001; i++){
			if(a[i].f and a[i].s){
				cout << "YES" << endl;
				cout << 1 << " " << i << endl;
				break;
			}
		}

		if (i == 1001) cout << "NO" << endl;
	}
	exit(0);
}
