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

int c, x, t, n;
int pass;
vector<int> tt(3);
vector<vector<int>> v(3);

void correct(int &time, int &now){
    int rem = now - time;
    time += rem;
    if(rem % x != 0) time += x - rem % x;
    pass = 0;
}

bool solve(int i, int s){
    if(s + tt[i] > t) return false;

    int time = 0;
    pass = 0;
    for(int p: v[i]){
        // Enter before it
        if(s <= p){
            if(time + x < s) correct(time, s);
            if(pass == c-1 or time + tt[i] <= t)
                return true;
        }
        if(time + x < p) correct(time, p);
        if(pass == c-1){
            pass = 1;
            time = p;
        } else pass += 1;
    }
    if(time + x < s) correct(time, s);
    if(pass == c-1 or time + tt[i] <= t) return true;

    return false;
}

int32_t main(){ _
    cin >> c >> x >> t >> n;
    for(int &i: tt) cin >> i;
    while(n--){
        int p, i; cin >> p >> i; i--;
        v[i].pb(p);
    } for(int i = 0; i < 3; i++) sort(v[i].begin(), v[i].end());

    int st = 0, en = t;
    while(st != en){
        int m = (st+en+1)/2;
        bool ok = false;
        for(int i = 0; i < 3; i++) ok = ok or solve(i, m);
        if(ok) st = m;
        else en = m-1;
    }

    cout << st << endl;
	exit(0);
}
