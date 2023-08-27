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
    int s, b;
    while(cin >> s >> b){
        if(s == 0 and b == 0) break;
        vector<int> cc(s);
        vector<int> x(b);
        for(int &i: cc) cin >> i;
        for(int &i: x) cin >> i;
        pair<vector<ll>, vector<ll>> dp;
        dp.first  = vector<ll>(s-1, 0);
        dp.second = vector<ll>(s-1, 0);
        


        reverse(x.begin(), x.end());
        ll ans = LINF;
        for(int round = 0; round < s; round++){
            
            vector<int> v(s-1);
            for(int i = 0; i < s-1; i++) v[i] = cc[(i+round) % s] + cc[(i+1+round) % s];
            int sz = s-1;
            for(int i = sz-1; i >= 0; i--){
                if(i == sz-1)
                    dp.first[i] = x[0] * v[i];
                else
                    dp.first[i] = min(ll(x[0]) * ll(v[i]), dp.first[i+1]);
            }
            
            if(b == 1)
                ans = min(ans, *min_element(dp.first.begin(), dp.first.end()));
            for(int k = 1, off = 2; k < b; k++, off+=2){
                auto& [dpa, dpn] = dp;
                for(int i = sz-off-1; i >= 0; i--){
                    if(i == sz-off-1)
                        dpn[i] = dpa[i+2] + x[k] * v[i];
                    else
                        dpn[i] = min(dpa[i+2] + ll(x[k]) * ll(v[i]), dpn[i+1]);
                    if(k == b-1) ans = min(ans, dpn[i]);
                }
                dpa = dpn;
                fill(dpn.begin(), dpn.end(), 0);
            }
        }

        cout << -ans << endl;
    }
    exit(0);
}
