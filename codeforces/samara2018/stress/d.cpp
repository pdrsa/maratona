#include <bits/stdc++.h>

using namespace std;

//#pragma GCC optimize ("O3")

/*
    VERIFICAR:
    - Corner cases
    - Estouro de variavel
    - Acesso indevido de memoria
    
    MODULO NEGATIVO
    int modulo(int x,int N){
        return (x % N + N) %N;
    }

*/

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct dinic {
	const bool scaling = false; // com scaling -> O(nm log(MAXCAP)),
	int lim;                    // com constante alta
	struct edge {
		int to, cap, rev, flow; // para, capacidade, id da reversa, fluxo
		bool res; // se a aresta eh residual
		edge(int to_, int cap_, int rev_, bool res_)
			: to(to_), cap(cap_), rev(rev_), flow(0), res(res_) {}
	};

	vector<vector<edge>> g;
	vector<int> lev, beg;
	ll F;
	dinic(int n) : g(n), F(0) {}

	void add(int a, int b, int c) { // de a pra b com cap. c
		g[a].push_back(edge(b, c, g[b].size(), false));
		g[b].push_back(edge(a, 0, g[a].size()-1, true));
	}
	bool bfs(int s, int t) {
		lev = vector<int>(g.size(), -1); lev[s] = 0;
		beg = vector<int>(g.size(), 0);
		queue<int> q; q.push(s);
		while (q.size()) {
			int u = q.front(); q.pop();
			for (auto& i : g[u]) {
				if (lev[i.to] != -1 or (i.flow == i.cap)) continue;
				if (scaling and i.cap - i.flow < lim) continue;
				lev[i.to] = lev[u] + 1;
				q.push(i.to);
			}
		}
		return lev[t] != -1;
	}
	int dfs(int v, int s, int f = INF){
		if (!f or v == s) return f;
		for (int& i = beg[v]; i < g[v].size(); i++) {
			auto& e = g[v][i];
			if (lev[e.to] != lev[v] + 1) continue;
			int foi = dfs(e.to, s, min(f, e.cap - e.flow));
			if (!foi) continue;
			e.flow += foi, g[e.to][e.rev].flow -= foi;
			return foi;
		}
		return 0;
	}
	ll max_flow(int s, int t) {
		for (lim = scaling ? (1<<30) : 1; lim; lim /= 2)
			while (bfs(s, t)) while (int ff = dfs(s, t)) F += ff;
		return F;
	}
	vector<pair<int, int> > get_cut(int s, int t) {
		max_flow(s, t);
		vector<pair<int, int> > cut;
		vector<int> vis(g.size(), 0), st = {s};
		vis[s] = 1;
		while (st.size()) {
			int u = st.back(); st.pop_back();
			for (auto e : g[u]) if (!vis[e.to] and e.flow < e.cap)
				vis[e.to] = 1, st.push_back(e.to);
		}
		for (int i = 0; i < g.size(); i++) for (auto e : g[i])
			if (vis[i] and !vis[e.to] and !e.res) cut.push_back({i, e.to});
		return cut;
	}
};

// set<ii> vis;
int n, k;

vector<vector<bool>> vis(301, vector<bool>(301));
vector<vector<int> > resp;

bool dfs(int at, dinic& d, vector<int> path) {
    if(at == n+1) {
        path.pop_back();
        resp.pb(path);
        return true;
    }
    for(auto e : d.g[at]) {
        if(!e.res && !vis[at][e.to]) {
            vis[at][e.to] = true;
            vector<int> temp = path;
            temp.pb(e.to);
            if(dfs(e.to, d, temp)) {
                return true;
            }
        }
    }
    return false;
}

int main() { _
    cin >> n >> k;
    dinic d(n+2);
    int a;
    for(int I=0; I<k; I++) {
        //cin >> a;
        a = I+1;
        d.add(0, a, 1);
    }
    for(int I=0; I<k; I++) {
        //cin >> a;
        a = 2*(I+1);
        d.add(a, n+1, 1);
    }
    char c;
    for(int I=0; I<n; I++) {
        for(int J=0; J<n; J++) {
            //cin >> c;
            if(true) {
                d.add(I+1, J+1, 1);
            }
        }
    }
    ll fluxo = d.max_flow(0, n+1);
    if(fluxo < k) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        while(dfs(0, d, vector<int>()));
        vector<ii> print;
        for(vector<int> r : resp) {
            for(int I=0; I<r.size()-1; I++) {
                print.pb({r[I], r[I+1]});
            }
        }
        cout << print.size() << endl;
        for(ii p : print) {
            cout << p.f << " " << p.s << endl;
        }
    }
	return 0;
}
