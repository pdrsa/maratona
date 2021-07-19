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
		
		vector<int> d(n+1);
		for(int i = 1; i <= n; i++) cin >> d[i];
		
		vector<int> r(n+1);
		vector<int> g(n+1);
		vector<int> ngg, ng;
		
		for(int i = 1; i <= n; i++){
			if(r[d[i]] != 0){
				g[i] = 0;
				ngg.pb(i);
			}

			else{
				g[i] = d[i];
				r[d[i]] = i;
			}
		}
		
		for(int i = 1; i <= n; i++) if(r[i] == 0) ng.pb(i);
		cout << n - ngg.size() << endl;
		
		if(ng.size() == 1){
			if(ng[0] == ngg[0]){
				g[r[d[ngg[0]]]] = ngg[0];
				g[ngg[0]] = d[ngg[0]];
			}

			else g[ngg[0]] = ng[0];
		}
		
		else{

			while(ng.size() > 0){
				if(ng.size() > 2){

					if(ngg[ngg.size() - 1] == ng[ng.size() - 1]){
						g[ngg[ngg.size() - 1]] = ng[ng.size() - 2];
						ng[ng.size() - 2] = ng[ng.size() - 1];
					}

					else g[ngg[ngg.size() - 1]] = ng[ng.size() - 1];
				
					ngg.pop_back(), ng.pop_back();
				}

				else{

					if(ngg[0] != ng[0] and ngg[1] != ng[1])
						g[ngg[0]] = ng[0], g[ngg[1]] = ng[1];
					
					else g[ngg[1]] = ng[0], g[ngg[0]] = ng[1];

					ngg.pop_back(), ngg.pop_back();
					ng.pop_back(), ng.pop_back();
				}

			}
		
		}

		for(int i = 1; i <= n; i++) cout << g[i] << " ";
		cout << endl;
	}
	exit(0);
}
