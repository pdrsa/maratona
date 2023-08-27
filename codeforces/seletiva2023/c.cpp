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

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
 
int uniform(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}
 
template<int MOD> struct str_hash { // 116fcb
	static int P;
	vector<ll> h, p;
	str_hash(string s) : h(s.size()), p(s.size()) {
		p[0] = 1, h[0] = s[0];
		for (int i = 1; i < s.size(); i++)
			p[i] = p[i - 1]*P%MOD, h[i] = (h[i - 1]*P + s[i])%MOD;
	}
	ll operator()(int l, int r) { // retorna hash s[l...r]
		ll hash = h[r] - (l ? h[l - 1]*p[r - l + 1]%MOD : 0);
		return hash < 0 ? hash + MOD : hash;
	}
};
template<int MOD> int str_hash<MOD>::P = uniform(256, MOD - 1); // l > |sigma|

int32_t main(){ _
	int n, m; cin >> n >> m;
    unordered_set<int> st;
    while(n--){
        string s; cin >> s;
        str_hash h(s);
        st.insert(h(0, s.size()));
    }
    
    while(m--){
        string s; cin >> s;
        bool ok = false;
        for(int i = 0; i < int(s.size()); i++){
            string new_s1 = s;
            string new_s2 = s;

            if(s[i] == 'a'){
                new_s1[i] = 'b';
                new_s2[i] = 'c';
            }
            if(s[i] == 'b'){
                new_s1[i] = 'a';
                new_s2[i] = 'c';
            }
            if(s[i] == 'c'){
                new_s1[i] = 'b';
                new_s2[i] = 'a';
            }
            
            str_hash h1(new_s1), h2(new_s2);
            if(st.count(h1(0, int(new_s1.size())) or st.count(h2(0, int(new_s2.size()))))) ok = true;
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    exit(0);
}
