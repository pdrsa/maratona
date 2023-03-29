//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
// #define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int32_t main(){ _
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		set<int> s;
		for(int i = 0; i < n; i++){
			int a; cin >> a;
			s.insert(a);
		}
		int k = s.size();
		for(int i = 0; i < n; i++){
			if(i < k) cout << k << " ";
			else cout << i+1 << " ";
		}
		cout << endl;
	}
	exit(0);
}
