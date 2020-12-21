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

int main(){ 
	int tt; cin >> tt;
	while(tt--){
		int len; cin >> len;
		int k; cin >> k;
		int ans = 0;
		vector<vector<int>> ed(len);
		vector<bool> che(len);
		vector<int> l;
		vector<int> dg(len);
		for(int i = 0; i < len-1; i++){
			int v1, v2;
			cin >> v1 >> v2;
			v1--; v2--;
			ed[v1].pb(v2);
			ed[v2].pb(v1);
		}
		for(int i = 0; i < len; i++)
			if(ed[i].size() == 1) l.pb(i);
		
		int x = 0;
		while(x != l.size()){
			int v = l[x];
			che[v] = true;
			for(auto u: ed[v]){
				if(che[u]) continue;
				//cout << "Leaf " << v+1 <<  " found node " << u+1 << endl;
				dg[u]++;
				if(dg[u] % k == 0){
					ans++;
					if(dg[u] == ed[u].size() - 1){
						l.pb(u);
						//cout << "New leaf " << u+1 << endl;
					}
				}
			}
			x++;
		}

		cout << ans << endl;
	}
	exit(0);
}
