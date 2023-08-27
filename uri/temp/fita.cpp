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

vector<int> des, des_rev;

vector<int> dobra(vector<int> &fita, int k){
    map<int, int> nf;
    int n = fita.size();

    int mini = INF;
    for(int i = 0; i < n-k; i++){
        int cur = fita[k+i];
        mini = min(mini, k-i-1);
        nf[k-i-1] = (k-i-1 >= 0 ? cur + fita[k-i-1] : cur);
    }
    
    vector<int> res;
    for(int i = 0; i < mini and i < n; i++) res.pb(fita[i]);
    for(auto [x, v]: nf) res.pb(v);
    
    return res;
}

bool brute(vector<int> &fita){
    if(fita == des or fita == des_rev) return true;
    for(int i = 1; i < fita.size(); i++){
        vector<int> nf = dobra(fita, i);
        if(brute(nf)) return true;
    }

    return false;
}

int main(){ _
    int n;
    while(cin >> n){
        vector<int> fo(n); for(int &i: fo) cin >> i;
        int m; cin >> m;
        des.resize(m);
        for(int i = 0; i < m; i++) cin >> des[i];
        des_rev = des;
        reverse(des_rev.begin(), des_rev.end());
        
        vector<int> ex = dobra(fo, 4);
        // for(int i: ex) cout << i << " ";
        // cout << endl;
        
        cout << (brute(fo) ? "S" : "N") << endl;
    }
    exit(0);
}
