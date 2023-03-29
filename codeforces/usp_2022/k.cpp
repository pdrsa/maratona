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
	ll n, b; cin >> n >> b;
    
    map<int, int> m;
    while(n--){
        ll x, y, t, v; cin >> x >> y >> t >> v;
        if(y < x or y - x <= t or (y + b - 1)/b > t) continue;
        if(m.count(-v)) m[-v] = 1;
        else m[-v] += 1;
    }
    
    ll ans   = 0;
    ll tick = 0;
    ll pays = 0;
    for(auto [key, value]: m){
        //cout << "Diposto a: "<< -key << " tem " << value << endl;
        pays += value;
        if(pays * (-key) >= ans){
            ans  = pays * (-key);
            tick = -key;
        }
    }

    cout << tick << endl;
    
    exit(0);
}
