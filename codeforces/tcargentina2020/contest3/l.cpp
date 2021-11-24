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

const ll is_query = -(1LL<<62);
struct line {
    ll m, b;
    mutable function<const line*()> succ;
    bool operator<(const line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};

struct dynamic_hull : public multiset<line> { // will maintain upper hull for maximum
    const ll inf = LLONG_MAX;
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;

		/* compare two lines by slope, make sure denominator is not 0 */
        ll v1 = (x->b - y->b);
        if (y->m == x->m) v1 = x->b > y->b ? inf : -inf;
        else v1 /= (y->m - x->m);
        ll v2 = (y->b - z->b);
        if (z->m == y->m) v2 = y->b > z->b ? inf : -inf;
        else v2 /= (z->m - y->m);
        return v1 >= v2;
    }
    void insert_line(ll m, ll b) {
        auto y = insert({ m, b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    ll eval(ll x) {
        auto l = *lower_bound((line) { x, is_query });
        return l.m * x + l.b;
    }
};

int main(){ //_
	int n; cin >> n;
	vector<ll> v(n+1); for(int i = 1; i <= n; i++) cin >> v[i];
	vector<ll> p(n+1); for(int i = 1; i <= n; i++) p[i] = p[i-1] + v[i];

	ll ori = 0;
	for(ll i = 1; i <= n; i++) ori += i*v[i];

	ll ans = 0;
	if(true){
		dynamic_hull ch;
		// Left to Right
		for(int l = n; l >= 1; l--){
			ch.insert_line(l, -p[l]);
			ans = max(ans, ch.eval(v[l]) + p[l] - v[l] * l);
		}
	}
	if(true){
		dynamic_hull ch;
		// Right to Left
		for(int r = 1; r <= n; r++){
			ch.insert_line(r, -p[r-1]);
			ans = max(ans, ch.eval(v[r]) + p[r-1] - v[r]*r);
		}
	}
	
	cout << ori + ans << endl;
	exit(0);
}
