#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5 + 10, MOD = 1e9 + 7;

int bit[MAX];

void add(int x, int p) {
	for (p++; p <= MAX - 5; p += p & -p) bit[p] = (bit[p] + x) % MOD;
}

int pref(int p) {
	int ret = 0;
	for (p++; p > 0; p -= p & -p) ret = (ret + bit[p]) % MOD;
	return ret;
}

int query(int l, int r) {
	return ((pref(r) - pref(l - 1)) % MOD + MOD) % MOD;
}

int main(){ _
	int n;
	cin >> n;
	vector<bool> on(n - 1);
	vector<int> jump(n - 1);

	ll ans = 0;
	for (int i = 0; i < n - 1; i++) {
		int c;
		cin >> c;
		ans += c;
		on[i] = c != 0;
	}
	for (int i = 0; i < n - 1; i++) {
		int k;
		cin >> k;
		jump[i] = i + k;
	}

	vector<int> next(n - 1);
	int prox = INF;
	for (int i = n - 2; i >= 0; i--) {
		next[i] = prox;
		if (on[i]) prox = i;
	}

	add(1, n-1);
	for (int i = n - 2; i >= 0; i--) {
		add(query(i + 1, min(jump[i], next[i])), i);
	}

	/*cout << "next" << endl;
	for (int i : next) cout << i << ' ';
	cout << endl;

	cout << "memo" << endl;
	for (int i = 0; i < n; i++) cout << query(i, i) << ' ';
	cout << endl;*/

	cout << ans << ' ' << query(0, 0) << endl;

	exit(0);
}
