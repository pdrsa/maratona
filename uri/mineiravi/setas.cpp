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

int n;
vector<vector<pair<int,int>>> g;

int dijkstra(int a, int b){

    priority_queue<pair<int, int>> q;
    vector<int> d(n, INF);
    q.push({0, a});
    d[a] = 0;
    while(not q.empty()){
        auto [vcost, v] = q.top(); q.pop();
        
        if(-vcost > d[v]) continue;
        for(auto [u, ucost]: g[v]) if(d[u] > d[v] + ucost){
            d[u] = d[v] + ucost;
            q.push({-d[u], u});
        }
    }

    return d[b];
}

int main(){ _
    int s, a, b; cin >> n >> s >> a >> b; a--, b--;
    g.resize(n);
    // Vizinho, Peso
    while(s--){
        int x, y; cin >> x >> y; x--, y--;
        g[x].emplace_back(y, 0);
        g[y].emplace_back(x, 1);
    }
    
    int c1 = dijkstra(a, b);
    int c2 = dijkstra(b, a);
    
    if(c1 == c2) cout << "Bibibibika" << endl;
    else if(c2 > c1) cout << "Bibi: " << c1 << endl;
    else cout << "Bibika: " << c2 << endl; 

    exit(0);
}
