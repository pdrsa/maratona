//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> iill;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
int main(){ _
    int n, m, k; cin >> n >> m >> k;
    
    vector<pair<char, int>> mv;
    while(k--){
        char c; cin >> c;
        int i; cin >> i;
        mv.emplace_back(c, i);
    }
    reverse(mv.begin(), mv.end());
    
    vector<int> p(4);
    set<int> lin, col;
    int pp = mv.size() % 4;
    int cl = 0, cc = 0;
    for(auto [c, i]: mv){
        pp--; pp = (pp + 4) % 4;
        if(c == 'L'){
            if(lin.count(i)) continue;
            p[pp] += m - cc;
            lin.insert(i); cl++;
        } else{
            if(col.count(i)) continue;
            p[pp] += n - cl;
            col.insert(i); cc++;
        }
    }
    cout << "R" << p[0] << " H" << p[1] << " C" << p[2] << " P" << p[3] << endl;
	exit(0);
}
