//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> iill;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9 + 7;
const int MAX = 2e5 + 10;
const int SQ = std::sqrt(MAX);
const int BLK = (MAX + SQ - 1) / SQ;
int v[MAX];
int tru[MAX];

int n, k, q;
int freq[MAX], cnt[BLK];
ll prod[BLK];

ll fexp(ll a, ll e) {
    ll ans = 1;
    while (e) {
        if (e & 1)
            ans = ans * a % MOD;
        a = a * a % MOD;
        e >>= 1; 
    }
    return ans;
};

inline void insert(int p) {
	int o = v[p];
	freq[o]++;
    cnt[o/SQ]++;
    prod[o/SQ] *= tru[o];
    prod[o/SQ] %= MOD;
}

inline void erase(int p) {
	int o = v[p];
	freq[o]--;
    cnt[o/SQ]--;
    prod[o/SQ] *= fexp(tru[o], MOD - 2);
    prod[o/SQ] %= MOD;
}


inline ll hilbert(int x, int y) {
	static int N = (1 << 20);
	int rx, ry, s;
	ll d = 0;
	for (s = N/2; s>0; s /= 2) {
		rx = (x & s) > 0;
		ry = (y & s) > 0;
		d += s * ll(s) * ((3 * rx) ^ ry);
		if (ry == 0) {
			if (rx == 1) {
				x = N-1 - x;
				y = N-1 - y;
			}
			swap(x, y);
		}
	}
	return d;
}

#define HILBERT true
vector<int> MO(vector<pair<int, int>> &q) {
	int m = q.size();
	vector<int> ord(m);
	iota(ord.begin(), ord.end(), 0);
#if HILBERT
	vector<ll> h(m);
	for (int i = 0; i < m; i++) h[i] = hilbert(q[i].first, q[i].second);
	sort(ord.begin(), ord.end(), [&](int l, int r) { return h[l] < h[r]; });
#else
	sort(ord.begin(), ord.end(), [&](int l, int r) {
		if (q[l].first / SQ != q[r].first / SQ) return q[l].first < q[r].first;
		if ((q[l].first / SQ) % 2) return q[l].second > q[r].second;
		return q[l].second < q[r].second;
	});
#endif
	vector<int> ret(m);
	int l = 0, r = -1;

	for (int x : ord) {
		int ql, qr;
		tie(ql, qr) = q[x];
		while (r < qr) insert(++r);
		while (l > ql) insert(--l);
		while (l < ql) erase(l++);
		while (r > qr) erase(r--);

        ll ans = 1;
        int at = k;
        for (int i = BLK - 1; i >= 0; --i) {
            if (cnt[i] <= at) {
                at -= cnt[i];
                ans = (ans * prod[i]) % MOD;
            } else {
                for (int j = (i+1)*SQ - 1; j >= i*SQ; --j) {
                    int mi = min(freq[j], at);
                    ans *= fexp(tru[j], mi);
                    ans %= MOD;
                    at -= mi;
                }
                break;
            }
        }

        cout << ql << ", " << qr << " = " << ans << endl;
		ret[x] = ans;
	}
	return ret;
}

int main(){ _

    cin >> n >> k >> q;

    vector<int> bag;
    
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        bag.push_back(tru[i]);
    }

    sort(bag.begin(), bag.end());
    bag.erase(unique(bag.begin(), bag.end()), bag.end());
    for (int i = 0; i < n; i++) {
        v[i] = int(lower_bound(bag.begin(), bag.end(), tru[i]) - bag.begin());
    }

    for (int i = 0; i < bag.size(); i++)
        tru[i] = bag[i];
    
    for (int i = 0; i < BLK; i++)
        prod[i] = 1;

    vector<pair<int, int>> queries(q);
    for (auto &[l, r] : queries) {
        cin >> l >> r;
        --l, --r;
    }
    
    auto ans = MO(queries);
    for (auto x : ans) {
        cout << x << endl;
    }

	exit(0);
}
