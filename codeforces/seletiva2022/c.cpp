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
    int n; cin >> n;
    vector<int> v(n);
    for(int &i: v) cin >> i;
    ll ans = 0;
    for(int i = 1; i < n; i++){
        ans += max(0, v[i-1] - v[i]); 
    }
    cout << ans << endl;
	exit(0);
}
