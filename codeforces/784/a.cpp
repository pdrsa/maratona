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
        int a; cin >> a;
        int div = 4;
        if(a >= 1400 and a < 1600) div = 3;
        if(a >= 1600 and a < 1900) div = 2;
        if(a >= 1900) div = 1;
        cout << "Division " << div << endl;
    }
	exit(0);
}
