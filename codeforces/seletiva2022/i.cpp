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
	string s; cin >> s;
    vector<char> sub;
    for(char c: s){
        while(sub.size() and sub.back() < c) sub.pop_back();
        sub.pb(c);
    }
    for(char c: sub) cout << c;
    cout << endl;
    exit(0);
}
