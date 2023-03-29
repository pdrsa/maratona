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
        int n, m; cin >> n >> m;
        vector<vector<char>> g(n, vector<char> (m));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> g[i][j];

        for(int epochs = 0; epochs < 55; epochs++)
            for(int i = n-1; i >= 1; i--)
                for(int j = 0; j < m; j++)
                    if(g[i][j] == '.' and g[i-1][j] == '*')
                        swap(g[i][j], g[i-1][j]);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) cout << g[i][j];
            cout << endl;
        }
    }
    exit(0);
}
