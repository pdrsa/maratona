//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int c, x, T, n;

int solve(vector<ll> &tuk, int t){
    ll arr  = 0;
    ll pass = 0;
    ll ans  = 0;
    for(int i = 0; i < tuk.size(); i++){
        if(tuk[i] + t > T) break;

        if(tuk[i] > arr + x){
            if(arr+x+t <= T) ans = max(ans, arr+x);
            arr += ((tuk[i] - arr)/x) * x;
            pass = 0;
        }

        if(pass+1 == c or tuk[i] == arr+x){
            if(tuk[i]+t <= T) ans = max(ans, tuk[i]);
            pass = 0;
            arr = tuk[i];
        }
        else pass++;
    }
    
    if(pass+1 == c)
        ans = max(ans, min(arr+x, T-t));

    if(arr+t+x <= T){
        ll sobra = T - arr - t;
        ll viagens = sobra/x;
        ans = max(ans, arr + (viagens * x));
    }

    return ans;
}

int32_t main(){ _
    cin >> c >> x >> T >> n;
    int tuk1, tuk2, tuk3; cin >> tuk1 >> tuk2 >> tuk3;
    vector<vector<ll>> tuk(3);
    while(n--){
        int t, g; cin >> t >> g;
        tuk[g-1].pb(t);
    }
    for(int i = 0; i < 3; i++) sort(tuk[i].begin(), tuk[i].end());
    
    cout << max({solve(tuk[0], tuk1), solve(tuk[1], tuk2), solve(tuk[2], tuk3)}) << endl;
    exit(0);
}
