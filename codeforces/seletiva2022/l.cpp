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
    map<char, int> m;
    for(char c: s){
        if(m.count(c)) m[c]++;
        else m[c] = 1;
    }
    cout << min({m['i'], m['t'], int((m['n'] - 1) / 2), int(m['e']/3)}) << endl;
    exit(0);
}
