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
		
		vector<ll> firstr(10, -1), lastr(10, -1);
		vector<ll> firstc(10, INF), lastc(10, -1);
		vector<vector<iill>> ocu(10);

		// By row
		for(ll i = 0; i < n; i++){
			string s; cin >> s;
			for(ll j = 0; j < n; j++){

				int aux = s[j] - '0';
				//Row
				if(firstr[aux] == -1) firstr[aux] = i;
				lastr[aux] = i;
				//Column
				firstc[aux] = min(firstc[aux], j);
				lastc[aux]  = max(lastc[aux], j);

				ocu[aux].pb({i,j});
			}
		}

		vector<ll> ans(10, 0);
		for(int t = 0; t <= 9; t++){
			for(auto oc:ocu[t]){
				//if(t == 5) cout << "OC: " << oc.f << " " << oc.s << endl;

				// Base on Row
				ll lenb = max(oc.s, n - oc.s - 1);
				ll lenh = max(lastr[t] - oc.f, oc.f - firstr[t]);
				//if(t == 5)cout << "Len B Row " << lenb << endl;
				ans[t] = max(ans[t], lenb * lenh);

				// Base on Column
				lenb = max(oc.f, n - oc.f - 1);
				lenh = max(lastc[t] - oc.s, oc.s - firstc[t]);
				//if(t == 5)cout << "Len B Col " << lenb << endl;
				ans[t] = max(ans[t], lenb * lenh);
			}
		}


		for(auto u: ans) cout << u << " ";
		cout << endl;
	}
	exit(0);
}
