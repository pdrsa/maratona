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

int el(int n){
	if(n == 0) return 1;
	else return 3*el(n-1);
}

int main(){ _
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		vector<int> dif(n); for(int &i: dif) cin >> i;
		set<int> has;
		has.insert(0);
		
		for(int x: dif){
			vector<int> add;
			for(int a: has) add.pb(a-x), add.pb(a+x);
			for(int a: add) has.insert(a);
		}
		
		if(has.size() < el(n)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	exit(0);
}
