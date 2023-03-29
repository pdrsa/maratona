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

int32_t main(){ _
    int n; cin >> n;
    vector<int> sobe(n);
    vector<int> dist(n);
    vector<vector<pair<int, bool>>> g(n);
    vector<bool> v(n);
    for(int i = 1; i < n; i++){
        int a, b; cin >> a >> b; a--, b--;
        g[a].pb({b, false}), g[b].pb({a, true});
    }

    int sobet = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    while(!q.empty()){
        auto [x, co] = q.front(); q.pop();
        v[x] = true;
        for(auto [y, r]: g[x]) if(!v[y]){
            sobe[y] = co + r;
            dist[y] = dist[x] + 1;
            q.push({y, sobe[y]});
            sobet += r;
        }
    }

    int ans = INF;
    vector<int> var;
    for(int i = 0; i < n; i++){
        int now = dist[i] - sobe[i];
        now += sobet - sobe[i];
        if(now < ans){
            ans = now;
            var.clear();
            var.pb(i+1);
        }
        else if(now == ans) var.pb(i+1);
    }
    cout << ans << endl;
    for(auto i: var) cout << i << " ";
    cout << endl;
	exit(0);
}
