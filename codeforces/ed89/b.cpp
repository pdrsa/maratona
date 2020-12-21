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
		int n, m, x; cin >> n >> x >> m;
		bool flag = false;
		bool flag2;
		int l, r;
		vector<ii> itv;
		int ma = 0, me = INF;
		for(int i = 0; i < m; i++){
			cin >> l >> r;
			if(l <= x and x <= r){
				if(!flag) itv.pb({l,r});
				flag = true;
			}
			if(!flag) continue;
			flag2 = false;
			for(auto u:itv){
				if(l <= u.s and r >= u.f){
					flag2 = true;
					if(r > ma) ma = r;
					if(l < me) me = l;
				}
			}

			if(flag2) itv.pb({l,r});
		}

		if(ma != 0 and me != INF) cout << (ma - me) + 1 << endl;
		else cout << 1 << endl;
	}
	exit(0);
}
