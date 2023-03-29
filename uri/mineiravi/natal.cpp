//DUDUUU!
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

vector<int> beleza;
vector<vector<tuple<int, int, int>>> v; //[id, viz, beleza]
vector<bool> corto;

int dfs(int root, int last) {
	int valor = 0;
	for(auto [id, next, bel] : v[root]) {
		if(next == last) continue;
		int x = dfs(next, root);
		corto[id] = ((bel + x) <= 0);
		if(!corto[id])
			valor += x + bel;
	}
	return valor;
}

vector<int> resposta;
int podar(int root, int last) {
	int valor = 0;
	for(auto [id, next, bel] : v[root]) {
		if(next == last) continue;
		if(corto[id]) resposta.pb(id);
		else {
			valor += bel;
			valor += podar(next, root);
		}
	}
	return valor;
}

int main(){ _
	int n; cin >> n;
	beleza.resize(n);
	v.resize(n); 
	corto.resize(n-1);
	for(int i = 0; i < n-1; i++) {
		int d, a, b, w; cin >> d >> a >> b >> w;
		v[a].pb({d, b, w});
		v[b].pb({d, a, w});
	}

	int blaaa = dfs(0, -1);
	int end = podar(0, -1);

	sort(resposta.begin(), resposta.end());
	cout << end << " " << resposta.size() << endl;
	if(resposta.size() > 0) {
		for(int i = 0; i < resposta.size(); i++){
			cout << resposta[i];
			if(i != resposta.size() - 1) cout << " ";
		}
		cout << endl;
	}

	return 0;
}
