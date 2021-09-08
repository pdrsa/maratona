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

vector<int> p;

int find(int x){
	return p[x] = (p[x] == x ? x : find(p[x]));
}

void uni(int x, int y){
	x = find(x), y = find(y);
	p[x] = y;
}

int main(){ _
	int n, m; cin >> n >> m;
	p.resize(n);
	iota(p.begin(), p.end(), 0);

	while(m--){
		int a, b; cin >> a >> b;
		a--, b--;
		uni(a, b);
	}

	ll ans = n;
	set<int> a;
	for(int i = 0; i < n; i++) a.insert(find(i));
	ans -= a.size();

	cout << (1LL << ans) << endl;
	exit(0);
}
