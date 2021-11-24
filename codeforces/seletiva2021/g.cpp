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
const int MAX = 150010;

ll dp[2][MAX];

template<class T> struct minqueue {
	deque<pair<T, int>> q;

	void push(T x) {
		int ct = 1;
		while (q.size() and x < q.front().first)
			ct += q.front().second, q.pop_front();
		q.push_front({x, ct});
	}
	void pop() {
		if (q.back().second > 1) q.back().second--;
		else q.pop_back();
	}
	T min() { return q.back().first; }
};

int32_t main(){ _
	ll n, m, d; cin >> n >> m >> d;
	vector<ll> a(m+1), b(m+1), time(m+1);
	
	for(int i = 1; i <= m; i++) cin >> a[i] >> b[i] >> time[i];
	
	for(int j = 1; j <= n; j++)
		dp[1][j] = b[1] - abs(a[1] - j);


	for(int i = 2; i <= m; i++){
		minqueue<ll> q;
		int now = i%2, prev = (1 - i%2);
		ll t = time[i] - time[i-1];
		for(ll k = 1; k <= min(n, t*d); k++) q.push(-dp[prev][k]);

		for(int j = 1; j <= n; j++){ // On position j at launching i
			dp[now][j] =  b[i] - abs(a[i] - j);
			if(j - t*d > 1) q.pop(); // Pop
			if(j + t*d <= n) q.push(-dp[prev][j + t*d]); // Push
			dp[now][j] -= q.min();
		}
	}

	ll ans = -LINF;
	for(int j = 1; j <= n; j++) ans = max(ans, dp[m % 2][j]);
	cout << ans << endl;
	exit(0);
}
