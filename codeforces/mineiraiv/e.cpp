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
    char  c;
    int p   = 0;
    int dir = 1;
    while(1){
        cin >> c; if(c == '#') break;

        if(c == '?'){
            cout << p+1 << " ";
            continue;
        }

        if(c == 'A' or c == '7') p += dir;
        if(c == 'Q') dir = -dir;
        
        p += dir;
        p = (p + n) % n;
    }
    cout << endl;
	exit(0);
}
