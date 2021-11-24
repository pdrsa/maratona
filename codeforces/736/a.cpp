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

vector<int> v;
int ans;

void add(int a, int b){
	if(a < b) swap(a, b);

	if(v[b] == 0) ans--;
	v[b]++;
}

void del(int a, int b){
	if(a < b) swap(a, b);
	v[b]--;
	if(v[b] == 0) ans++;
}

int32_t main(){ _
	int n, m; cin >> n >> m;
	v.resize(n);
	ans = n;

	while(m--){
		int a, b; cin >> a >> b;
		a--, b--;
		add(a, b);
	}

	int q; cin >> q;
	while(q--){
		int c; cin >> c;
		if(c == 1){
			int a, b; cin >> a >> b;
			a--, b--;
			add(a, b);
		} else if(c == 2){
			int a, b; cin >> a >> b;
			a--, b--;
			del(a, b);
		} else cout << ans << endl;
	}
	exit(0);
}
