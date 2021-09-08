#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
	int n; cin >> n;
	vector<int> v((1<<n));
	for (auto &i : v) cin >> i;

	vector<int> at;
	priority_queue<int> pq;
	at.push_back(0);
	string ans = "";
	for (int i = 1; i < (1<<n); i++) {
		int a = v[i];
		if (pq.size() and pq.top() == -a) {
			pq.pop();
			continue;
		}
		ans += char(a);
		vector<int> nat;
		for (auto u : at) 
			nat.push_back(u), nat.push_back(u + a), pq.push(-u-a);
		pq.pop();
		at = nat;
	}

	cout << ans << endl;

	exit(0);
}
