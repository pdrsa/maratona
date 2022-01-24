//JP - Not in Kansas Anymore
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e5 + 10;

int ans[MAX];

vector<int>   g[MAX];
vector<ii>    q[MAX];
ord_set<ii>   s[MAX];
unordered_map<int, int> m[MAX];

void add(int a, int b){ // Adds b to a

	if(s[a].size() < s[b].size()){ // A must be > b
		s[a].swap(s[b]);
		m[a].swap(m[b]);
	}
	
	for(auto [qt, c]: s[b]){
		if(m[a].count(c)){
			int cur = m[a][c];

			s[a].erase({cur, c});
			s[a].insert({cur + qt, c});
			m[a][c] = cur + qt;
		} else{
			m[a][c] = qt;
			s[a].insert({qt, c});
		}
	}

	ord_set<ii>().swap(s[b]);
	unordered_map<int, int>().swap(m[b]);
}

void dfs(int x, int pai){
	for(int u: g[x]) if(u != pai) { dfs(u, x); add(x, u); }
	for(auto [k, pos]: q[x]) ans[pos] = s[x].size() - s[x].order_of_key({k, -INF});
}

int main(){ _
	int n, mm; cin >> n >> mm;
	for(int i = 0; i < n; i++){
		int c; cin >> c;
		s[i].insert({1, c});
		m[i][c] = 1;
	}
	
	for(int i = 0; i < n-1; i++){
		int a, b; cin >> a >> b;
		a--, b--;
		g[a].pb(b); g[b].pb(a);
	}
	
	for(int i = 0; i < mm; i++){
		int x, k; cin >> x >> k;
		q[x-1].pb({k, i});
	}
	
	dfs(0, -1);
	for(int i = 0; i < mm; i++) cout << ans[i] << " ";
	cout << endl;

	exit(0);
}
