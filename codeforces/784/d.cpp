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

bool check(string s){
    if(s.size() == 0) return true;
    bool r = false, b = false;
    for(char c: s){
        if(c == 'B') b = true;
        if(c == 'R') r = true;
    }

    return r and b;
}

int32_t main(){ _
    int tt; cin >> tt;
    while(tt--){
        int n; cin >> n;
        string s; cin >> s;
        string cur;
        bool ok = true;
        for(char c: s){
            if(c == 'W'){
                ok = ok and check(cur);
                cur = "";
            }
            else cur.push_back(c);
        }
        ok = ok and check(cur);
        cout << (ok ? "YES" : "NO") << endl;
    }
	exit(0);
}
