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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n % 2 == 0){
            cout << -1 << endl;
            continue;
        }
        vector<int> s;
        while(n > 1){
            if((n + 1) % 4 == 0){
                s.pb(2);
                n = (n-1) / 2;
            }
            else{
                s.pb(1);
                n = (n+1) / 2;
            }
        }
        reverse(s.begin(), s.end());
        if(s.size() > 40) cout << -1 << endl;
        else{
            cout << s.size() << endl;
            for(int i: s) cout << i << " ";
            cout << endl;
        }
    }
	exit(0);
}
