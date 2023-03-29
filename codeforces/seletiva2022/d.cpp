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
    int n, m; cin >> n >> m;
    set<int> al;
    int notas[n][m];
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < m; j++) notas[i][j] = int(s[j] - '0');
    }

    for(int j = 0; j < m; j++){
        int maxi = -1; 
        vector<int> maxidx;
        for(int i = 0; i < n; i++){
            if(notas[i][j] == maxi) maxidx.pb(i);
            if(notas[i][j] > maxi){
                maxidx.clear();
                maxidx.pb(i);
                maxi = notas[i][j];
            }
        }
        for(auto a: maxidx) al.insert(a);
    }
    cout << al.size() << endl;
	exit(0);
}
