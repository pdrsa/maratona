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
const int MAX = 2005;

vector<int> g[MAX];
set<int> gg[MAX];

vector<int> dg;
vector<int> p;
int target, n;

int dfs(int x){
    for(auto u: g[x]){
        if(u == target and p[x] != u) return x;
        if(p[u] == -1){
            p[u] = x;
            int got = dfs(u);
            if(got != -1) return got;
        }
    }

    return -1;
}

int search(int x){
    if(dg[x] < 4) return -1;

    p = vector<int>(n, -1);
    p[x] = -2; target = x;
    return dfs(x);
}

void solve(){
    int m; cin >> n >> m;
    for(int i = 0; i < n; i++) g[i].clear(), gg[i].clear();
    dg = vector<int>(n);

    while(m--){
        int a, b; cin >> a >> b;
        a--, b--;
        dg[a]++, dg[b]++;
        g[a].pb(b), g[b].pb(a);
        gg[a].insert(b), gg[b].insert(a);
    }

    for(int i = 0; i < n; i++){
        int x = search(i);
        if(x == -1) continue;
        
        set<int> w;
        vector<pair<int, int>> ans;
        ans.pb({x, i});
        w.insert(i);

        int init = x;
        while(x != i){
            //cout << "x: " << x << "p[x]: " << p[x] << endl;
            w.insert(x);
            // Early Stop
            if(x != init and gg[x].find(i) != gg[x].end()){
                ans.pb({x, i});
                break;
            }
            ans.pb({x, p[x]});
            x = p[x];
        }

        int count = 0;
        for(int u: g[i]){
            if(w.find(u) == w.end()){
                ans.pb({u, i});
                count++;
            }
            if(count == 2) break;
        }
        
        cout << "YES" << endl;
        cout << ans.size() << endl;
        for(auto [a, b]: ans) cout << a+1 << " " << b+1 << endl;
        return;
    }
    cout << "NO" << endl;
}


int32_t main(){ _
    int tt; cin >> tt;
    while(tt--) solve();
	exit(0);
}
