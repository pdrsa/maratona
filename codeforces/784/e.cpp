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
        vector<vector<ll>> st(15, vector<ll> (15, 0));
        vector<ll> stc(15, 0);
        vector<ll> endc(15, 0);
        
        int n; cin >> n;
        while(n--){
            string s; cin >> s;
            int a = s[0] - 'a';
            int b = s[1] - 'a';

            st[a][b]++;
            stc[a]++;
            endc[b]++;
        }
        
        ll ans = 0;
        for(int i = 0; i < 15; i++){
            for(int j = 0; j < 15; j++){
                // Start Equal
                ll m1 = stc[i];
                // End Equal
                ll m2 = endc[j];
                // Equal
                ll m3 = st[i][j];
                
                ans += m3 * (m1 - m3);
                ans += m3 * (m2 - m3);
                stc[i] -= m3, endc[j] -= m3;
            }
        }

        cout << ans << endl;
    }
	exit(0);
}
