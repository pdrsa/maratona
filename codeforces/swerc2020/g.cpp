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
const int LOG = 24;
const int MAX = 1e6 + 50;
vector<vector<int>> up(LOG);
vector<vector<int>> s(LOG);
vector<int> dc;
vector<int> p;

int n, k;

int dfs(int x){
	// cout << "on " << x << " p[x] = " << p[x] << endl;
	if(up[0][x] == 0) return dc[x] = 1;
	if(dc[up[0][x]] != INF) dc[x] = dc[up[0][x]] + 1;
	if(dc[x] != INF) return dc[x];
	
	if(p[up[0][x]] == 0){
		p[up[0][x]] = x;
		dc[x] = min(dfs(up[0][x]) + 1, dc[x]);
	}

	else{
		int stop = up[0][x];
		int q = x;
		int sc = 1;
		while(q != stop){
			q = p[q];
			sc++;
		}
		while(q != x){
			dc[q] = sc;
			q = up[0][q];
		}
		// cout << "Found on " << x << " Cycle size = " << sc << endl;
		dc[x] = sc;
	}

	return dc[x];
}

void pre(){
	for(auto &v: up) v.assign(n + 50, 1);
	for(auto &v: s)  v.resize(n + 50);

	for(int log = 0; log < LOG; log++) up[log][0] = 0;
	for (int i = 2; i <= n; i++)
		for (int j = i; j <= n; j += i)
			up[0][j]++;
	for(int i = 1; i <= n; i++){
		up[0][i] += i, up[0][i] %= n;
		s[0][i] = up[0][i];
	}

	for(int log = 1; log < LOG; log++){
		for(int i = 1; i <= n; i++){
			up[log][i] = up[log-1][ up[log-1][i] ];
			s[log][i]  = s[log-1][i] + s[log - 1][ up[log-1][i] ];
		}
	}
}

ll bl(int q){
	ll sum = 0, ans = q;
	int kth = k-1;

	for(int i = 0; i < LOG; i++)
		if(kth & (1 << i)) sum += s[i][ans], ans = up[i][ans];
	
	return sum;
}

int main(){ //_
	cin >> n >> k;
	pre();
	dc.assign(n, INF);
	p.resize(n+10);
	
	ll mini = LINF, mina;
	for(int i = 0; i < n; i++){
		if(dc[i] == INF) dfs(i);
		if(dc[i] + 1 < k) continue;
		if(bl(i) + i < mini) mini = bl(i) + i, mina = i;
	}
	if(mini == LINF) cout << -1 << endl;
	else{
		while(k--){
			cout << mina << " ";
			mina = up[0][mina];
		}
		cout << endl;
	}

	exit(0);
}
