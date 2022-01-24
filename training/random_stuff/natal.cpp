#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;
const int MAX = 1e6 + 10;


vector<tuple<int, int, int>> g[MAX];
// Vizinho, Identificador, Valor

vector<int>  sz(1e6 + 10);
vector<bool> rem(1e6 + 10);

int dfs(int x, int pai){
	sz[x] = 0;

	for(auto [u, d, w]: g[x]) if(u != pai){
		int s = dfs(u, x);
		
		// Checo se o galho vale a pena
		if(w <= 0 and -w >= s)
			rem[d] = true; // Se não vale picota
		else
			sz[x] += w + s; // Se vale soma na resposta
	}
	
	return sz[x];
}

void dfsCut(int x, int pai, bool cut){
	for(auto [u, d, w]: g[x]) if(u != pai){
		if(!cut){ // Se eu não passei por um cortado
			// Checo se o galho que eu to passando foi cortado
			dfsCut(u, x, rem[d]);
		}
		else{ // Se eu já passei por um cortado
			rem[d] = false; // Marco como não cortado
			dfsCut(u, x, true); // Continuo avisando que já passei por um cortado
		}
	}
}

int main(){ _
	int n; cin >> n;
	for(int i = 0; i < n-1; i++){
		int d, a, b, w; 
		cin >> d >> a >> b >> w;
		
		// Salvando os vizinhos
		g[a].emplace_back(b, d, w);
		g[b].emplace_back(a, d, w);
	}

	dfs(0, -1);
	dfsCut(0, -1, false);

	int ans = 0;
	for(auto x: rem) ans += x;

	cout << sz[0] << " " << ans << endl;
	
	bool print = false;
	for(int i = 0; i < n-1; i++){
		if(rem[i]){
			if(!print) print = true;
			else cout << " ";
			cout << i;
		}
	}
	cout << endl;
	exit(0);
}
