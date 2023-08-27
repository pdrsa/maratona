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
        int n, s1, s2; cin >> n >> s1 >> s2;
        vector<pair<int, int>> r(n);
        for(int i = 0; i < n; i++){
            int k; cin >> k;
            r[i] = {-k, i};
        }
        sort(r.begin(), r.end());

        vector<int> l1, l2;

        for(int i = 0; i < n; i++){
            auto [cur, x] = r[i];
            cur = -cur;
            ll cr1 = (l1.size() + 1) * s1;
            ll cr2 = (l2.size() + 1) * s2;
            if(cr1 < cr2 or ((cr1 == cr2) and (s2 < s1)))
                l1.pb(x+1);
            else
                l2.pb(x+1);
        }

        cout << l1.size() << " ";
        for(int i: l1) cout << i << " ";
        cout << endl;
        
        cout << l2.size() << " ";
        for(int i: l2) cout << i << " ";
        cout << endl;

    }
    exit(0);
}
