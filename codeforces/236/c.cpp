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
		int n, p; cin >> n >> p;
		int ed = 0;
		bool ok = false;
		for(int i = 1; i < n; i++){
			for(int j = i+1; j <= n; j++){
				cout << i << " " << j << endl;
				ed++;
				if(ed == (2*n +p)){
					ok = true; break;
				}
			}
			if(ok) break;
		}
	}
	exit(0);
}
