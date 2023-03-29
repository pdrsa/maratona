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
    n *= 2;
    set<int> a, b, c;
    for(int i = 1; i <= n; i++){
        char k; cin >> k;
        if(k == 'A') a.insert(i);
        if(k == 'B') b.insert(i);
        if(k == 'C') c.insert(i);
    }

    set<int> ba, bb, bc;
    ba = a, bb = b, bc = c;

    {
    // Erase BC
    vector<pair<int, int>> ans;
    vector<int> rm;
    for(int i: b){
        auto iter = c.upper_bound(i);
        if(iter == c.end()) break;
        int j = *iter;
        ans.pb({i, j}); rm.pb(i);
        c.erase(j);
        //cout << i << " " << j << endl;
    }
    for(int i: rm) b.erase(i);
    
    // Erase AC
    rm.clear();
    for(int i: c){
        auto iter = a.upper_bound(i);
        if(iter == a.begin() or a.empty()) break;
        iter--;
        int j = *iter;
        ans.pb({j, i}); rm.pb(i);
        a.erase(j);
        //cout << i << " " << j << endl;
    }
    for(int i: rm) c.erase(i);
    
    // Erase AB
    rm.clear();
    for(int i: a){
        auto iter = b.upper_bound(i);
        if(iter == b.end()){
            cout << "NO" << endl;
            exit(0);
        }
        int j = *iter;
        ans.pb({i, j}); rm.pb(i);
        b.erase(j);
        //cout << i << " " << j << endl;
    }
    for(int i: rm) a.erase(i);

    if(not a.empty() or not b.empty() or not c.empty()){
        cout << "NO" << endl;
        exit(0);
    }
    
    cout << "YES" << endl;
    for(auto [i,j]: ans) cout << i << " " << j << endl;

    exit(0);
}
