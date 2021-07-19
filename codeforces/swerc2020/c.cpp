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

int m, n, k;

vector<vector<int>> g;
vector<bool> d;
vector<pair<double, double>> sen;

void dfs(int x){
	d[x] = true;
	for(int u: g[x]) if(!d[u]) dfs(u);
}

bool solve(double s){
//	cout << fixed << setprecision(5) << s << " : ";
	g.assign(k+4, vector<int>());
	// Paredes: 
	// 0 = cima, 1 = esquerda, 2 = direita, 3 = baixo
	for(int i = 4; i < k+4; i++){
		double ux, uy;
		ux = sen[i].f, uy = sen[i].s;
		// Cima
		if(uy + s >= n) g[i].pb(0), g[0].pb(i);
		// Esquerda
		if(ux - s <= 0) g[i].pb(1), g[1].pb(i);
		// Direita
		if(ux + s >= m) g[i].pb(2), g[2].pb(i);
		// Baixo
		if(uy - s <= 0) g[i].pb(3), g[3].pb(i);
		
		// Outros sensores
		for(int j = i+1; j < k+4; j++){
			double x, y;
			x = sen[j].f, y = sen[j].s;
			
			double dx, dy;
			dx = abs(x - ux), dy = abs(y - uy);
			
			if(double(dx * dx + dy * dy) <= (2*s)*(2*s))
				g[j].pb(i), g[i].pb(j);
		}
	}


	bool ans = true;
	
	// Esquerda até Baixo ou Direita
	d.assign(k+4, false);
	dfs(1);
	ans = ans and !d[3] and !d[2];
	//cout << endl << "Esquerda chega: " << endl;
	//cout << "Baixo: " << d[3] << " Direita: " << d[2] << endl;
	//cout << "Cima chega: " << endl;
	// Cima até Baixo ou Direita
	d.assign(k+4, false);
	dfs(0);
	ans = ans and !d[3] and !d[2];
	//cout << "Baixo: " << d[3] << " Direita: " << d[2] << endl;
	
	//cout << ans << endl;
	return ans;
}


int main(){ _
	cin >> m >> n >> k;
	sen.resize(k+4);
	for(int i = 4; i < k+4; i++) cin >> sen[i].f >> sen[i].s;
	double ini = 0, fim = 1e6;

	for(int i = 0; i < 100; i++){
		double mid = (ini + fim)/2;
		if(solve(mid)) ini = mid;
		else fim = mid;
	}
	
	cout << fixed << setprecision(5) <<  ini << endl;
	exit(0);
}
