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
        int n, k; cin >> n >> k;
        vector<vector<int>> m(n, vector<int> (n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> m[i][j];
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(m[i][j] != m[n-i-1][n-j-1]) count++;
            }
        }
        
        count /= 2;
        if(k >= count and ((k-count) % 2 == 0 or n % 2 == 1)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
	exit(0);
}
