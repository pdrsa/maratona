//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

// #define int ll
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> iill;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool sorted(vector<int> &v){
	for(int i = 0; i < v.size() - 1; i++)
		if(v[i] > v[i+1]) return false;
	return true;
}

int32_t main(){ _
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		vector<int> v(n); for(int &i: v) cin >> i;
		int c = 0;
		while(!sorted(v)){
			for(int i = (c % 2); i < n-1; i += 2)
				if(v[i] > v[i+1]) swap(v[i], v[i+1]);
			c++;
		}
		cout << c << endl;
	}
	exit(0);
}
