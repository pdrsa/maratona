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
const ll MAX = 1e5 + 200;

vector<ll> p(MAX, -1);
vector<ll> imp(MAX);
vector<ll> sz(MAX, 1);
vector<vector<int>> g(MAX);
vector<set<tuple<ll,ll,ll>>> bc(MAX);

pair<ll, ll> dfs_c(int x){
    p[x] = -2;
    for(int u: g[x]) if(p[u] == -1) {
        auto [szu, impu] = dfs_c(u);
        p[u] = x;
        sz[x] += szu;
        imp[x] += impu;
        bc[x].insert({-szu, u, impu});
    }

    return make_pair(sz[x], imp[x]);
}

int32_t main(){ _
	int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> imp[i];
    vector<ll> imp_o = imp;

    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b; a--, b--;
        g[a].pb(b), g[b].pb(a);
    }
    dfs_c(0);
    
    /*cout << "BEFORE ------------ " << endl;

    cout << "Parents: " << endl;
    for(int i = 0; i < n; i++) cout << (p[i] == -2 ? -2 : p[i]) << " ";
    cout << endl << "Importance: " << endl;
    for(int i = 0; i < n; i++) cout << imp[i] << " ";
    cout << endl << "Size: " << endl;
    for(int i = 0; i < n; i++) cout << sz[i] << " ";
    cout << endl << "Queues: " << endl;
    for(int i = 0; i < n; i++){
        cout << i << ":" << endl;
        for(auto [bb, bbb, idx]: bc[i]) cout << idx << " ";
        cout << endl << endl;
    }
    
    cout << "AFTER -----------------" << endl;
    */
    while(m--){
        ll op, x; cin >> op >> x; x--;
        if(op == 1)
            cout << imp[x] << endl;
        else{
            // Retrieve
            auto pfx = bc[x].begin();
            if (pfx == bc[x].end()) continue;

            auto fx = *pfx;
            auto [szfx, ifx, impfx] = fx;
            szfx = -szfx;
            
            // Parent
            p[ifx] = p[x];
            p[x] = ifx;
            
            int par = p[ifx];
            if(par != -2)
                bc[par].erase({-sz[x], x, imp[x]});

            // Sz
            sz[x] -= sz[ifx];
            sz[ifx] += sz[x];

            // Imp
            imp[x] -= imp[ifx];
            imp[ifx] += imp[x];

            // Queue
            bc[x].erase(fx);
            bc[ifx].insert({-sz[x], x, imp[x]});

            // Parent
            if(par != -2)
                bc[par].insert({-sz[ifx], ifx, imp[ifx]});
           }
    }

    /*cout << "Parents: " << endl;
    for(int i = 0; i < n; i++) cout << (p[i] == -2 ? -2 : p[i]) << " ";
    cout << endl << "Importance: " << endl;
    for(int i = 0; i < n; i++) cout << imp[i] << " ";
    cout << endl << "Size: " << endl;
    for(int i = 0; i < n; i++) cout << sz[i] << " ";
    cout << endl << "Queues: " << endl;
    for(int i = 0; i < n; i++){
        cout << i << ":" << endl;
        for(auto [bb, bbb, idx]: bc[i]) cout << idx << " ";
        cout << endl << endl;
    }*/
    exit(0);
}
