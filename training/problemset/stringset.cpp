//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
// #define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MG  = 350;
const ll MOD = (1LL<<61) - 1;

// KMP
template<typename T> vector<int> pi(T s) {
	vector<int> p(s.size());
	for (int i = 1, j = 0; i < s.size(); i++) {
		while (j and s[j] != s[i]) j = p[j-1];
		if (s[j] == s[i]) j++;
		p[i] = j;
	}
	return p;
}

template<typename T> int matching(T& s, T& t) {
	vector<int> p = pi(s), match;
	for (int i = 0, j = 0; i < t.size(); i++) {
		while (j and s[j] != t[i]) j = p[j-1];
		if (s[j] == t[i]) j++;
		if (j == s.size()) match.push_back(i-j+1), j = p[j-1];
	}
	return match.size();
}

// Hashing

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

// Solving

unordered_set<string> big;
unordered_set<ll> small;

void add(string s){
	if(s.size() < MG){
		str_hash sh(s);
		small.insert(sh(0, int(s.size()) - 1));
	}
	else big.insert(s);
}

void erase(string s){
	if(s.size() < MG){
		str_hash sh(s);
		small.erase(sh(0, int(s.size()) - 1));
	}
	else big.erase(s);
}

int find(string s){
	int ret = 0;
	for(string a: big) ret += matching(a, s);
	
	str_hash sh(s); // KKKKKKKKKKKKKKKK BUILDEI NO LUGAR ERRADO
	for(int i = 0; i < MG; i++){
		for(int j = 0; j < int(s.size()) - i; j++)
			if(small.count(sh(j, j+i))) ret++;
	}

	return ret;
}

int main(){ _
	int m; cin >> m;
	while(m--){
		int t; cin >> t;
		string s; cin >> s;
		if(t == 1) add(s);
		if(t == 2) erase(s);
		if(t == 3) cout << find(s) << endl;
	}

	exit(0);
}
