//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> iill;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
	int n, q; cin >> n >> q;
    vector<int> a(n);
    for(int &i: a) cin >> i;
    sort(a.begin(), a.end());
    
    vector<pair<int, int>> b;
    for(int i = 0; i < q; i++){
        int x, y; cin >> x >> y; x--;
        b.pb({x, 0}), b.pb({y, 1});
    }
    sort(b.begin(), b.end());
    vector<int> p(n);
    int c = 0;
    int b_idx = 0;

    for(int i = 0; i < n; i++){
        while(b_idx < b.size() and b[b_idx].f == i){
            // cout << "i " << i << " b_idx " << b_idx << " b[b_idx] " << b[b_idx].f << endl;
            if(b[b_idx].s) c--;
            else c++;
            b_idx++;
        }
        p[i] = c;
    }
    sort(p.begin(), p.end());
    // for(int i: p) cout << i << " ";
    ll ans = 0;
    for(int i = 0; i < n; i++) ans += ll(p[i]) * ll(a[i]);
    cout << ans << endl;
    exit(0);
}
