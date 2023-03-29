//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int32_t main(){ _
	int n; cin >> n;
    vector<int> a(n+1), b(n+1);
    for(int &i: a) cin >> i;
    for(int &i: b) cin >> i;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(b[i] > a[i]){
            int miss = (b[i] - a[i] + 1) / 2;
            ans += miss;
            b[i+1] += miss;
        }
    }
    if(b[n] > a[n]) cout << -1 << endl;
    else cout << ans << endl;
    exit(0);
}
