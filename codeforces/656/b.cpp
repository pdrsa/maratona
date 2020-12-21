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
		int n; cin >> n;
		vector<int> ans;
		set<int> p;
		int aux;
		for(int i = 0; i < 2*n; i++){
			cin >> aux;
			if(p.count(aux) == 0){
				ans.pb(aux);
				p.insert(aux);
			}
		}

		for(int i = 0; i < n; i++) cout << ans[i] << " ";
		cout << endl;
	}
	exit(0);
}
