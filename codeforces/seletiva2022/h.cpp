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
    map<int, pair<int, int>> m;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        if(m.count(a)){
            m[a].first++;
            m[a].second++;
        } else m[a] = {1,1};

        if(b == a) continue;
        if(m.count(b)) m[b].second++;
        else m[b] = {0, 1};
    }
    int ans = INF;
    for(auto [k, p]: m){
        auto [a, b] = p;
        if(b >= (n+1)/2)
            ans = min(ans, ((n+1)/2) - a);
    }
    ans = max(ans, 0);
    if(ans != INF) cout << ans << endl;
	else cout << -1 << endl;
    exit(0);
}
