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
        ll n, k; cin >> n >> k;
        if(n % 2 == 0 or (k % 2 == 1 and k <= n))
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    exit(0);
}
