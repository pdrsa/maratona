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
    int t; cin >> t;
    while(t--){
        int l, r; cin >> l >> r;
        int ans = -1, n_ans;
        for(int i = l; i <= r; i++){
            int maxi = 0, mini = 10;
            int p = i;
            while(p > 0){
                maxi = max(maxi, p % 10);
                mini = min(mini, p % 10);
                p /= 10;
            }
            if(maxi - mini > ans){
                    ans = maxi - mini;
                    n_ans = i;
            }
            if(ans == 9) break;
        }
        cout << n_ans << endl;
    }
	exit(0);
}
