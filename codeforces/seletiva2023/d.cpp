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

void go(){
    int n, k; cin >> n >> k;
    deque<int> v;
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++){
            int x; cin >> x; v.pb(x);
        }
    }
    sort(v.begin(), v.end());
    
    ll ans = 0;
    for(int i = 0; i < k; i++){
        for(int j = n; j > 0; j--){
            if(j >= (n+1)/2){
                if (j == (n+1)/2) ans += v.back();
                v.pop_back();
            } else{
                v.pop_front();
            }
        }
    }

    cout << ans << endl;
}

int32_t main(){ _
	int t; cin >> t;
    while(t--){
        go();
    }
    exit(0);
}
