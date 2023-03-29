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

int main(){ _
	int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    while(m--){
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        g[a].pb({b, c});
        g[b].pb({a, c});
    }
    priority_queue<tuple<int, int, int>> pq;
    vector<int> vis(n);
    vector<int> pai(n, -1);
    pq.emplace(0, 0, -1);
    while(not pq.empty()){
        auto [w, v, p] = pq.top(); pq.pop();
        w = -w;
        if(vis[v]) continue;
        vis[v] = true;
        pai[v] = p;
        for(auto [u, w2]: g[v])
            pq.emplace(-w-w2, u, v);
    }
    if(pai[n-1] == -1){
        cout << -1 << endl;
        exit(0);
    }

    int x = n-1;
    vector<int> ans;
    while(x != -1){
        ans.pb(x+1); x = pai[x];
    }
    reverse(ans.begin(), ans.end());
    for(int i: ans) cout << i << " ";
    cout << endl;
    exit(0);
}
