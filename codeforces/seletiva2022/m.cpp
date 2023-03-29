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
	int n, k; cin >> n >> k;
    string s; cin >> s;
    if(k > 2){
        int ans = 0;
        for(int i = 1; i < n-1; i+=2){
            if(s[i] != s[i-1] and s[i] != s[i+1]) continue;
            if(s[i-1] != 'A' and s[i+1] != 'A') s[i] = 'A';
            else if(s[i-1] != 'B' and s[i+1] != 'B') s[i] = 'B';
            else if(s[i-1] != 'C' and s[i+1] != 'C') s[i] = 'C';
            ans++;
        }
        if(s[n-1] == s[n-2]){
            if(s[n-2] == 'A') s[n-1] = 'B';
            else(s[n-1] = 'A');
            ans++;
        }
        cout << ans << endl;
        cout << s << endl;
    }
    else{
        int ans1 = 0;
        string a1;
        char N = 'A';
        for(char c: s){
            if(c != N) ans1++;
            a1.pb(N);
            if(N == 'A') N = 'B';
            else N = 'A';
        }

        // ------------------------
        int ans2 = 0;
        string a2;
        N = 'B';
        for(char c: s){
            if(c != N) ans2++;
            a2.pb(N);
            if(N == 'A') N = 'B';
            else N = 'A';
        }
        if(ans1 < ans2){
            cout << ans1 << endl;
            cout << a1 << endl;
        } else{
            cout << ans2 << endl;
            cout << a2 << endl;
        }
    }
    exit(0);
}
