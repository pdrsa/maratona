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
		vector<ii> v(n);
		vector<int> p(n);
		for(int i = 0; i < n; i++){
			int a; cin >> a;
			v[i] = {a, i};
			p[i] = a;
		}

		sort(v.rbegin(), v.rend());
		int po = n;
		for(ii s: v){
			if(s.s < po){
				for(int i = s.s; i < po; i++) cout << p[i] << " ";
				po = s.s;
			}
		}
		cout << endl;
	}
	exit(0);
}
