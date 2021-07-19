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

bool eq(vector<int> v){
	for(int i = 0; i < v.size()-1; i++){
		if(v[i] != v[i+1]) return false;
	}
	return true;
}

int main(){ _
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		vector<int> v(n); for(int &i: v) cin >> i;
		int ans = 0;
		while(!eq(v)){
			vector<int> vc = v;
			for(int i = 0; i < n-1; i++) v[i] = gcd(vc[i], vc[i+1]);
			v[n-1] = gcd(vc[n-1], vc[0]);
			ans++;
		}
		// for(int i: v) cout << i << " ";
		//cout << endl;
		cout << ans << endl;
	}
	exit(0);
}
