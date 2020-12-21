//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
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
 
bool dis(int l1, int r1, int l2, int r2){
	int a, b, c, d;
	if(l1 < l2){
		a = l1; b = r1;
		c = l2; d = r2;
	}
	else{
		a = l2; b = r2;
		c = l1; d = r1;
	}
 
	if(b < c or a > d) return true;
	else return false;
}
 
int main(){ _
	int x, y, z, q, t; cin >> x >> y >> z >> q >> t;
	vector<vector<int>> fig;
	while(q--){
		int type; cin >> type;
		if(type == 1){
			vector<int> tf(7);
			cin >> tf[1] >> tf[3] >> tf[5];
			int aux;
			cin >> aux; tf[2] = tf[1]+aux-1;
			cin >> aux; tf[4] = tf[3]+aux-1;
			cin >> aux; tf[6] = tf[5]+aux-1;
			cin >> tf[0]; tf[0]--;
			
			bool can = true;
			for(auto f: fig){
				if(!(dis(f[1],f[2],tf[1],tf[2]) or dis(f[3],f[4],tf[3],tf[4])
					or dis(f[5],f[6],tf[5],tf[6]))){
					cout << -1 << endl;
					can = false;
					break;
				}
			}
			if(can){
				fig.pb(tf);
			}
		}
 
		else{
			vector<int> tf(7);
			vector<int> types(23);
			cin >> tf[1] >> tf[3] >> tf[2] >> tf[4] >> tf[6]; tf[5] = 0;
			for(auto f: fig){
				if(!(dis(f[1],f[2],tf[1],tf[2]) or dis(f[3],f[4],tf[3],tf[4])
					or dis(f[5],f[6],tf[5],tf[6]))){
						types[f[0]]++;
				}
			}
 
			int ans = 0;
			for(auto ty: types) if(ty > 0) ans++;
			cout << ans << endl;
		}
	}
 
	exit(0);
}
