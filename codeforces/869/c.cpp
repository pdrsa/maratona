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
	int n,q; cin >> n >> q;
    vector<int> a(n); for(int &i:a) cin >> i;
    vector<int> l, r;
    for(int i = 2; i < n; i++)
        if(a[i-2] >= a[i-1] and a[i-1] >= a[i])
            l.pb(i-2), r.pb(i);
    while(q--){
        int x, y; cin >> x >> y; x--, y--;
        
        // Primeiro que começa após o L
        auto it = lower_bound(l.begin(), l.end(), x);
        int lower = it - l.begin();
        
        // Primeiro que termina antes do R
        int upper = -INF;
        it = upper_bound(r.begin(), r.end(), y);
        if(it != r.begin())
            upper = it - r.begin() - 1;
        
        // cout << "Upper : " << upper << " Lower: " << lower << endl;
        cout << y-x+1-max(0, upper - lower + 1) << endl;
    }
    exit(0);
}
