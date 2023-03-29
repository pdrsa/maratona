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
    int n, m; cin >> n >> m;
    int x, y; cin >> x >> y;
    ll steps = 0;
    int k; cin >> k;
    while(k--){
        int dx, dy; cin >> dx >> dy;
        ll stx = LINF, sty = LINF;
        if(dx > 0) stx = (n-x)/dx;
        if(dx < 0) stx = (x-1)/(-dx);
        if(dy > 0) sty = (m-y)/dy;
        if(dy < 0) sty = (y-1)/(-dy);
        ll stpn = min(sty, stx);
        //cout << stpn << endl;
        x += dx*stpn;
        y += dy*stpn;
        steps += stpn;
    }
    cout << steps << endl;
	exit(0);
}
