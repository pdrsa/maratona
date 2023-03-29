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
	int n, x; cin >> n >> x;
    int sum = 0;
    while(n--){
        int a; cin >> a;
        sum += a;
    }
    sum = abs(sum);
    if(sum % x == 0) cout << sum/x << endl;
    else cout << sum/x + 1 << endl;
    exit(0);
}
