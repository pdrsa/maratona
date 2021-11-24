#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define FOR(i,a,n) for(ll i=a;i<n;i++)

typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll, ll, ll> t4;

const int INF = 0x3f3f3f3f;
const int LINF = 0x3f3f3f3f;

ll y, n, s, h, m;
ll   dp[51][26][5001];
bool dp1[51][26][5001];

vector<ll> next1;
vector<t4> v;

pair<ll, bool> solve(ll noite_left, ll stays_left, ll rate) {
	if(noite_left <= 0 or stays_left <= 0) return {0LL, false};
	if(rate >= m) return {LINF, false};

	auto [id, in, out, cost, bla] = v[rate];
	ll pego = solve(noite_left-(out-in), stays_left-1, next1[rate]).f + cost;
	ll deixo = solve(noite_left, stays_left, rate+1).f;

	dp[noite_left][stays_left][rate] = min(pego, deixo);
	dp1[noite_left][stays_left][rate] = pego < deixo;

	return {dp[noite_left][stays_left][rate], (pego < deixo)};
}

bool comp(t4 a, t4 b) {
	auto [id1, in1, out1, cost1, bla1] = a;
	auto [id2, in2, out2, cost2, bla2] = b;
	if(in1 == in2) return out1 < out2;
	return in1 < in2;
}

int32_t main() { _
	cin >> y >> n >> s >> h >> m;
	next1.resize(m+2, m);
	v.resize(m);
	ll iii = 1;
	for(auto &[id, in, out, cost, og] : v) {
		cin >> id >> in >> out >> cost;
		og = iii;
		iii++;
	}

	sort(v.begin(), v.end(), comp);

	// pega next
	FOR(i,0,m) {
		auto [id1, in1, out1, cost1, bla1] = v[i];
		FOR(j,i+1,m) {
			auto [id2, in2, out2, cost2, bla2] = v[j];
			if(id1 != id2 and in2 >= out1) {
				next1[i] = j;
				break;
			} else if(id1 == id2 and in2 > out1) {
				next1[i] = j;
				break;
			}
		}
	}

	FOR(i,0,n+1) {
		FOR(j,0,s+1) {
			for(int k = m; k >= 0; k--) {
				if(i == 0LL or j == 0LL){
					dp[i][j][k]  = 0LL;
					dp1[i][j][k] = false;
				}
				else if(k == m){
					dp[i][j][k]  = LINF;
					dp1[i][j][k] = false;
				}
				else {
					auto [id, in, out, cost, bla] = v[k];

					ll pego = dp[max(0LL, i-(out-in))][j-1][next1[k]] + cost;
					ll deixo = dp[i][j][k+1];

					dp[i][j][k]  = min(pego, deixo);
					dp1[i][j][k] = (pego < deixo);
				}
			}
		}
	}

	// for(auto i : next1) cout << i << " ";
	// cout << endl;

	ll res = dp[n][s][0];
	if(res >= LINF) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

	vector<ll> resposta;
	ll n1 = n, s2 = s, rate1 = 0;
	while(rate1 < m) {
		auto [id, in, out, cost, bla] = v[rate1];
		if(dp1[n1][s2][rate1]) {
			resposta.pb(bla);
			n1 = max(0LL, n-(out-in));
			s2 = max(0LL, s-1);
			rate1 = next1[rate1];
			if(n1 == 0 or s2 == 0) break;
		} else {
			rate1++;
		}
	}

	cout << (n1 <= 0 ? "NIGHTS" : "STAYS") << endl;
	cout << resposta.size() << endl;
	for(ll i : resposta) cout << i << " ";
	cout << endl;
	return 0;
}
