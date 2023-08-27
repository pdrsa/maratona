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

int32_t main(){ //_
	int tt; cin >> tt;
    while(tt--){
        int n, m; cin >> n >> m;
        vector<vector<int>> g(n);
        vector<int> w(n);
        for(int &i : w) cin >> i;
        while(m--){
            int a, b; cin >> a >> b; a--, b--;
            g[a].pb(b), g[b].pb(a);
        }
        bool okay = false;
        vector<bool> proc(n);
        for(int i = 0; i < n; i++) if(w[i] == 0) proc[i] = true;
        
        for(int x = 0; x < n; x++) if(proc[x]){
            int power = 0;
            priority_queue<pair<int, int>> q; q.push({-w[x], x});
            vector<bool> vis(n);
            while(not q.empty()){
                auto [k, v] = q.top(); q.pop();
                if(vis[v]) continue;
                if(w[v] <= power) power++;
                else continue;

                vis[v] = true;
                // cout << "Power is " << power << " on vertex " << v << endl;
                if(w[v] == 0) proc[v] = false; 
                for(int u: g[v]) if(not vis[u]) q.push({-w[u], u});
            }
            if(power == n){
                cout << "YES" << endl;
                okay = true;
                break;
            }
        }
        if(not okay) cout << "NO" << endl;
    }
    exit(0);
}
