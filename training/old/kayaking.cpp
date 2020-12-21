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
vector<int> k;
int b, n, e;
int sb, sn, se;
int nk;
vector<ii> st(6);

int getS(int m){
	int cb = b, cn = n, ce = e;
	int minK = INF;
	for(int i = 0; i < nk; i++){
		int sk = m / k[i];
		for(auto u: st){
			if(u.f >= sk){
				if(u.s == 1 and cb > 1) cb -= 2;
				else if(u.s == 2 and cb > 0 and cn > 0){
					cb--;cn--;
				}
				else if(u.s == 3 and cb > 0 and ce > 0){
					cb--; ce--;
				}
				else if(u.s == 4 and cn > 1) cn -= 2;
				else if(u.s == 5 and cn > 0 and ce > 0){
					cn--;
					ce--;
				}
				else if(u.s == 6 and ce > 1) ce -= 2;
				else continue;
				
				minK = min(minK, k[i] * u.f);
				break;
			}
		}
	}

	return minK;
}

bool solve(int m){
	int cb = b, cn = n, ce = e;
	for(int i = 0; i < nk; i++){
		bool can = false;
		for(auto u: st){
			if(u.f * k[i] >= m){
				if(u.s == 1 and cb > 1) cb -= 2;
				else if(u.s == 2 and cb > 0 and cn > 0){
					cb--;cn--;
				}
				else if(u.s == 3 and cb > 0 and ce > 0){
					cb--; ce--;
				}
				else if(u.s == 4 and cn > 1) cn -= 2;
				else if(u.s == 5 and cn > 0 and ce > 0){
					cn--;
					ce--;
				}
				else if(u.s == 6 and ce > 1) ce -= 2;
				else continue;
				
				can = true;
				break;
			}
		}

		if(!can) return false;
	}
	return true;
}

int main(){
	cin >> b >> n >> e;
	nk = (b+n+e)/2;
	cin >> sb >> sn >> se;
	st = {{sb+sb,1}, {sb+sn, 2}, {sb+se, 3}, {sn+sn, 4}, {sn+se, 5}, {se+se, 6}};
	sort(st.begin(), st.end());
	//for(auto u: st) cout << u.f << " " << u.s << endl;
	
	k.resize(nk);
	for(int i = 0; i < nk; i++) cin >> k[i];
	sort(k.begin(), k.end());
	int l = 0, r = 2 * 1e8 + 10;

	while(l < r){
		int m = (l+r+1)/2;
		if(solve(m)) l = m;
		else r = m-1;
	}

	cout << l << endl;

	exit(0);
}
