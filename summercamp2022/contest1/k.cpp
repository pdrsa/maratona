// Time: (ubiratan, EduardoFernandes, pedrosa)
// pedrosa

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
const int MAX = 1e5 + 50;

const ll MOD = (1ll<<61)-1;

ll mulmod(ll a, ll b) {
    const static ll LOWER = (1ll<<30)-1, GET31 = (1ll<<31)-1;
    ll l1 = a&LOWER, h1 = a>>30, l2 = b&LOWER, h2 = b>>30;
    ll m = l1*h2 + l2*h1, h = h1*h2;
    ll ans = l1*l2 + (h>>1) + ((h&1)<<60) + (m>>31) + ((m&GET31)<<30) + 1;
    ans = (ans&MOD) + (ans>>61);
    ans = (ans&MOD) + (ans>>61);
    return ans-1;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll uniform(ll l, ll r) {
    uniform_int_distribution<ll> uid(l, r);
    return uid(rng);
}

struct str_hash {
    static ll P;
    int n;
    string s;
    vector<ll> h, power;
    str_hash(string s_) : n(s_.size()), s(s_), h(n), power(n) {
        power[0] = 1;
        for (int i = 1; i < n; i++) power[i] = mulmod(power[i-1], P);
        h[0] = s[0];
        for (int i = 1; i < n; i++) h[i] = (mulmod(h[i-1], P) + s[i]) % MOD;
    }
    ll operator()(int i, int j) { // retorna hash da substring s[i..j]
        if (!i) return h[j];
        ll ret = h[j] - mulmod(h[i-1], power[j-i+1]);
        return ret < 0 ? ret+MOD : ret;
    }
};
ll str_hash::P = uniform(27, MOD-1);

set<pair<ll, ll>> set_hash[MAX];
map<ll, int> dict;

string strings_i[MAX];

vector<bool> removi(MAX);

int32_t main(){ _
	int q; cin >> q;
	for(int qq = 1; qq <= q; qq++){
		// cout << "-----------------------" << endl;
		int tipo; cin >> tipo;
		if(tipo == 1){ // Insert
			string s; cin >> s;
			strings_i[qq] = s;

			str_hash h(s);
			for(int i = 0; i < s.size(); i++){
				ll hash = h(s.size() - i - 1, s.size() - 1);
				
				// If I've already seen it
				if(dict.count(hash)){
					int value = dict[hash];
					set_hash[i].erase({value, hash});
					set_hash[i].insert({value + 1, hash});
					dict[hash]++;
				} else{
					dict[hash] = 1;
					set_hash[i].insert({1, hash});
				}
			}
		} else if(tipo == 2){ // Query
			int k, l; cin >> k >> l;
			if(set_hash[l-1].size() == 0){
				cout << "NO" << endl;
				continue;
			}

			ll value = (*set_hash[l-1].rbegin()).first;
			cout << (value >= k ? "YES" : "NO") << endl;
		} else{ // Delete
			int x; cin >> x;
			if(removi[x]) continue;
			else removi[x] = true;

			string s = strings_i[x];
			str_hash h(s);
			
			for(int i = 0; i < s.size(); i++){
				ll hash = h(s.size() - i - 1, s.size() - 1);
				
				//cout << "LOOP DELETE" << endl;
				int value = dict[hash];
				set_hash[i].erase({value, hash});
				set_hash[i].insert({value - 1, hash});
				dict[hash]--;
			}
		}
	}
	exit(0);
}
