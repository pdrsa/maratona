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
    int tt; cin >> tt;
    while(tt--){
        ll n; cin >> n;
 
 
        vector<ll> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a.rbegin(), a.rend());
        for(int i = 1; i < n; i++) a[i] += a[i-1];
        
        vector<ll> b(n);
        for(int i = 0; i < n; i++) cin >> b[i];
        sort(b.rbegin(), b.rend());
        for(int i = 1; i < n; i++) b[i] += b[i-1];
 
        ll l = n, r = 1e10;
 
        while(l < r){
            ll m = (l+r)/2;
 
            ll t = m - (m/4);
            ll sa = 0, sb = b[min(t-1, n-1)];
 
            sa += min(t, (m-n)) * 100;
 
            t -= (m-n);
            if(t > 0) sa += a[t-1];
            
            if(sa >= sb) r = m;
            else l = m+1;
        }
        
        cout << l - n << endl;
    }
    exit(0);
}
