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
    int st = 1, en = n;
    
    int dif = 1;
    bool left = true;
    while(n > 1){
        if(n % 2 == 0){
            if(left) en = en - dif;
            else st = st + dif;
        }
        dif *= 2;
        left = not left;
        n = n-(n/2);
    }
    if(left) cout << st << endl;
    else cout << en << endl;
    exit(0);
}
