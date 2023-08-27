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

int mv(int x, int y, int n, int m){
    
    if((x == 1 or x == n) and (y == 1 or y == m)) return 2;
    
    if(x==1 or x == n or y == 1 or y == m) return 3;
    
    return 4;
}

int32_t main(){ _
    int tt; cin >> tt;
    while(tt--){
        int n, m; cin >> n >> m;
        int x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
        cout << min(mv(x1, y1, n, m), mv(x2, y2, n, m)) << endl;
    }
	exit(0);
}
