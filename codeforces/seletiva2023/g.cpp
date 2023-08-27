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

struct dsu {
    vector<int> id, sz;
    dsu(int n) : id(n), sz(n, 1) { iota(id.begin(), id.end(), 0); }
    
    int find(int a) { return a == id[a] ? a : id[a] = find(id[a]); }

    void unite(int a, int b){
        a = find(a), b = find(b);
        if(a == b) return;
        if(sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b], id[b] = a;
    }
};

int32_t main(){ _
	int n, m; cin >> n >> m;
    dsu v(n+m);

    bool zebra = true;
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        while(k--){
            zebra = false;
            int x; cin >> x; x--;
            v.unite(i, n+x);
        }
    }

    int ans = 0;

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(v.find(i) != v.find(j)){
                ans++;
                v.unite(i, j);
            }
        }
    }
    
    if(zebra) cout << n << endl;
    else cout << ans << endl;
    exit(0);
}
