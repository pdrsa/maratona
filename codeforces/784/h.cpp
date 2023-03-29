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
    int tt; cin >> tt;
    while(tt--){
        int n, k; cin >> n >> k;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];

        vector<int> hm(31);
        for(int p = 0; p <= 30; p++){
            for(int i = 0; i < n; i++)
                if((1 << p) & v[i]) hm[p]++;
        }

        for(int p = 30; p >= 0; p--){
            if(k < (n - hm[p])) continue;
            for(int i = 0; i < n; i++){
                if(k == 0) break;
                int &x = v[i];
                
                if(x & (1 << p)) continue;
                else{
                    x |= (1 << p);
                    k--;
                }
            }
        }

        int ans = v[0];
        for(int i = 0; i < n; i++) ans &= v[i];
        cout << ans << endl;
    }
	exit(0);
}
