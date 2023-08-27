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

ll brute(ll l, ll r){
    ll ans = INF, ans_dig = l;
    for(ll i = l; i <= r; i++){
        ll maxi = i % 10, mini = i % 10;
        ll cur = i;
        
        while(cur > 0){
            maxi = max(cur % 10, maxi);
            mini = min(cur % 10, mini);
            cur /= 10;
        }
 
        if (maxi - mini < ans){
            ans = maxi - mini;
            ans_dig = i;
        }
    }
 
    return ans_dig;
}

int32_t main(){ _
	int tt; cin >> tt;
    while(tt--){
        ll l, r; cin >> l >> r;
        ll new_l = l, new_r = r;
        int cl = 0, cr = 0;
        while(new_l > 0) new_l /= 10, cl++;
        while(new_r > 0) new_r /= 10, cr++;
        if(cr > cl){
            while(l > 0){
                cout << 9;
                l /= 10;
            }
        }
        else cout << brute(l, r);
        cout << endl;
    }
    exit(0);
}
