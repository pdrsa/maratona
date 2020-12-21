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
	int q; cin >> q;
	while(q--){
		int n; cin >> n;
		vector<int> r(4 * n);
		for (int i = 0; i < 4 * n; i++) cin >> r[i];
		bool ans = true;
		sort(r.begin(), r.end());
		
		int a = r[0] * r[4 * n - 1];
		for(int i = 1; i < 2 * n; i++){
			if (r[i] * r[4*n - i - 1] != a){
				ans = false;
				break;
			}
		}
		
		int cont = 1;
		int at = r[0];
		for(int i = 1; i < 4*n; i++){
			if(r[i] == at) cont++;
			else{
				if(cont % 2 == 1){
					ans = false;
					break;
				}

				at = r[i];
				cont = 1;
			}
		}
		if (cont % 2 == 1) ans = false;

		if (ans) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	exit(0);
}
