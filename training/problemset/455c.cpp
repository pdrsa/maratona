//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MOD = 1e9 + 7;

ll sub(ll a, ll b){
    return (a-b+MOD)%MOD;
}

ll sum(ll a, ll b){
    return ((a%MOD) + (b%MOD)) % MOD;
}

int main(){ //_
    int n; cin >> n;

    vector<int> s;
    int id_l = 0;
    for(int i = 0; i < n; i++){
        char c; cin >> c;
        if(c == 'f') id_l++;
        else{
            s.pb(id_l);
            id_l = 0;
        }
    }
    
    int m = s.size();
    vector<vector<ll>> dp(m, vector<ll>(n+10));
    
    for(int i = s[0]; i <= n; i++) dp[0][i] = 1;
    for(int i = 1; i < m; i++){
        for(int id = 0; id <= n; id++){
            if(id < s[i]) continue;

            ll past  = (id > 0 ? dp[i][id-1] : 0);
            
            ll cant  = (id-s[i] > 0 ? dp[i-1][id-s[i]-1] : 0);
            ll total = dp[i-1][n-1];
            
            dp[i][id] = sum(past, sub(total, cant));
        }
    }
    
	cout << dp[m-1][n] << endl;
    exit(0);
}
