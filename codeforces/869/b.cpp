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
        int n; cin >> n;
        if(n>1 and n%2){
            cout << -1 << endl;
            continue;
        } else if (n == 1) cout << 1 << " ";
        
        for(int i = n-1; i >= 1; i -= 2) cout << i << " " << i + 1 << " ";
        cout << endl;
    }
	exit(0);
}
