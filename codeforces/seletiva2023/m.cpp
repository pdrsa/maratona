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
const int MAX = int(1e4)+2;

vector<int> g(MAX+10, INF);

void start(int x, int mv){
    if(x < 0 or x > MAX) return;
    if(g[x] > mv){
        g[x] = mv;
        start(x*2, mv+1);
        start(x-1, mv+1);
    }

    return;
}

int32_t main(){ _
	int n, m; cin >> n >> m;
    
    start(n, 0);
    
    cout << g[m] << endl;
    exit(0);
}
