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
const int MAX = 5e3+100;

 int main(){ _
	int n, q; cin >> n >> q;
	vector<int> f(n);

	vector<ii> p(q); for(auto &[a, b]: p){
		cin >> a >> b; a--, b--;
		for(int i = a; i <= b; i++) f[i]++;
	}

	int ans = 0;
	for(int i = 0; i < q; i++){
		for(int id = p[i].f; id <= p[i].s; id++) f[id]--;
		
		int cur = 0;
		for(int id = 0; id < n; id++) cur += (f[id] > 0);
		vector<int> d(n);
		for(int id = 0; id < n; id++) d[id] = (f[id] == 1);
		for(int id = 1; id < n; id++) d[id] += d[id-1];
		
		for(int j = i+1; j < q; j++){
			int curPair = cur - (d[p[j].s] - (p[j].f == 0 ? 0 : d[p[j].f - 1]) );
			ans = max(ans, curPair);
		}

		for(int id = p[i].f; id <= p[i].s; id++) f[id]++;
		
	}

	cout << ans << endl;
	exit(0);
}
