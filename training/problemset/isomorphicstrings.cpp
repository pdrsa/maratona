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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, q;
string s;

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
// primeiro parametro deve ser maior que o tamanho do alfabeto



vector<str_hash> hashes;
vector<int> ocur[26];

bool equal(int i, int j, int len){
	for(int c = 0; c < 26; c++){
		// Find first ocurrence
		auto it = lower_bound(ocur[c].begin(), ocur[c].end(), i);
		
		if(it == ocur[c].end()) continue;
		int f = *it; if(f > i + len - 1) continue; // Char doesn't occur on first range
		else{
			int c2 = int(s[f - i + j] - 'a'); // Equivalent to char on second range
			if(hashes[c](i, i+len-1) != hashes[c2](j, j + len - 1)) return false;
		}
	}

	return true;
}

int main(){ _
	cin >> n >> q;
	cin >> s;
	for(int i = 0; i < 26; i++){
		string c;
		for(int j = 0; j < n; j++){
			if(s[j] == char('a' + i)){
				c.pb('1');
				ocur[i].pb(j);
			}
			else c.pb('0');
		}
		str_hash now(c);
		hashes.pb(now);
	}

	while(q--){
		int i, j, len; cin >> i >> j >> len;
		cout << (equal(i-1, j-1, len) ? "YES" : "NO") << endl;
	}

	exit(0);
}
