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
const int MAX = 2e5;

int main(){ //_
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		vector<int> dif(n); for(int &i: dif) cin >> i;
		vector<int> v(n+1); v[0] = 0;
		for(int i = 1; i <= n; i++) v[i] = v[i-1] + dif[i-1];
		
		for(int i: v) cout << i << " ";
		cout << endl;

		//cout << (ans ? "YES" : "NO") << endl;	
	}
	exit(0);
}
