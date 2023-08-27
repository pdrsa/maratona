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

vector<int> comp(101);

int check(int f, int c){
    int of = f;
    for(int i = 0; i < c/2; i++){
        f -= min(comp[i], comp[c-i]);
    }
    if (f <= 0)
        return comp[c] + 2 * (f-comp[c]);
    else
        return INF;
}

int32_t main(){ //_
    comp[0] = INF;
    int n, m; 
    while(cin >> n >> m){
        cout << n << m;
        int l; cin >> l;
        int k; cin >> k;
        while(k--){
            int x; cin >> x;
            comp[x] += 1;
        }
    
        int ans = INF;
        if(m % l == 0)
            ans = min(ans, check(m/l, n));
        if(n % l == 0)
            ans = min(ans, check(n/l, m));

	    if(ans == INF) cout << "impossivel" << endl;
        else cout << ans << endl;
    }
    exit(0);
}
