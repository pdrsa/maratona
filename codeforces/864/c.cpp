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

int32_t main(){ //_
	int tt; cin >> tt;
    while(tt--){
        int n, m; cin >> n >> m;
        cout << "? " <<  1 << " " << 1 << endl;
        int line; cin >> line;
        line = line + 1;
        if(line > n or line > m){
            if(line > n){
                cout << "? " << 1 << " " << line << endl;
                int ans; cin >> ans;
                cout << "! " << 1+ans << " " << line << endl;
            } else{
                cout << "? " << line << " " << 1  << endl;
                int ans; cin >> ans;
                cout << "! " << line << " " << 1+ans << endl;
            }

            continue;
        }
        cout << "? " << 1 << " " << line << endl;
        int ans; cin >> ans;
        if(ans+1 < line) cout << "! " << 1+ans << " " << line << endl;
        else{
            cout << "? " <<  line << " " << 1 << endl;
            cin >> ans;
            cout << "! " << line << " " << 1+ans << endl;
        }
    }
    exit(0);
}
