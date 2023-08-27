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
        int n,k; cin >> n >> k;
        map<string, int> c;
        
        string ini; cin >> ini;
        n--;
        int ans = 1;
        while(n--){
            string s; cin >> s;
            if(s == ini) ans++;
        }
        cout << ans << endl;
    }
	exit(0);
}
