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
    ll ans = 0;
    vector<tuple<int, int, int>> v;
    for(int i =0; i < 2*n; i++){
        int a, b; cin >> a >> b;
        v.pb({a+b, min(a,b), max(a,b)});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        auto [a, b, c] = v[i];
        ans -= b;
    }
    for(int i = n; i < 2*n; i++){
        auto [a, b, c] = v[i];
        ans += c;
    }
    cout << ans << endl;
	exit(0);
}
