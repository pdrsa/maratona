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
    vector<int> a(27);
    int k;cin >> k; 
    string s; cin >> s;
    int n = s.size();
    // --
    int count = 0, first;
    for(int i = 0; i < n; i++){
        if(s[i] == '?')
            count++;
            else a[s[i] - 'a']++;
    }
    for(int i = 0; i < k; i++){
        if(a[i] == 0){
            first = i;
            break;
        }
    }
    // --
    int j = k - 1;
    for(int i = n/2 - (1-n%2); i > -1; i--){
        if(s[i] == '?'){
            if(s[n-i-1] == '?'){
                while(a[j] != 0 && j > 0)
                    j--;
                s[i] = j + 'a';
                s[n-i-1] = j + 'a';
                a[j] ++;
            }
            else s[i] = s[n-i-1];
        }
    }
    // Set
    for(int i = 0; i < n; i++) if(s[i] == '?') s[i] = s[n-i-1];

    // --
    for(int i = 0; i < n; i++){
            if(s[i] != s[n-i-1]){
                cout << "IMPOSSIBLE" << endl;
                exit(0);
            }
    }
    for(int i = 0; i < k; i++) a[i] = 0;
    for(int i = 0; i < n; i++) a[s[i] - 'a']++;
    for(int i = 0; i < k; i++)
            if(a[i] == 0){
                cout << "IMPOSSIBLE" << endl;
                exit(0);
            }
    cout << s << endl;
    exit(0);
}
