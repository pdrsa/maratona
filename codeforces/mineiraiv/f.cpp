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
    string s; cin >> s;
    unordered_map<char, int> m;
    
    int ans = 0;
    for(int l = 0, r = 0; r < n; r++){
        if(not(int(s[r]) >= int('a') and int(s[r]) <= int('z'))){
            l = r+1;
            m.clear();
        }

        if(not m.count(s[r])) m[s[r]] = 0;
        while(m[s[r]] > 0){
            m[s[l]]--;
            l++;
        }
        ans = max(ans, r-l+1);
        m[s[r]]++;
    }

    cout << ans << endl;
	exit(0);
}
