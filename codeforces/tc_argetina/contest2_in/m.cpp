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
	int n, m, k, t; cin >> n >> m >> k >> t;
	vector<ii> w;
	while(k--){
		int i, j; cin >> i >> j;
		w.pb({i, j});
	}
	sort(w.begin(), w.end());
	while(t--){
		ii p; cin >> p.f >> p.s;
		int nb = lower_bound(w.begin(), w.end(), p) - w.begin();
		if(nb < w.size() and w[nb] == p) cout << "Waste" << endl;
		else{
			int nc = ((p.f - 1) * m) + p.s;
			nc -= nb;
			nc = nc % 3;

			if(nc == 1) cout << "Carrots" << endl;
			if(nc == 2) cout << "Kiwis" << endl;
			if(nc == 0) cout << "Grapes" << endl;
		}
	}
	exit(0);
}
