#include <bits/stdc++.h>
using namespace std;

int eval(vector<int> a, int n) {
	int sum_all = accumulate(a.begin(), a.end(), 0);

	int mx = 0, cur = 0;
	// in the middle
	for (int i = 0; i < n; i++) {
		cur += a[i];
	}
	mx = max(mx, cur);
	for (int i = n; i < n*2; i++) {
		cur -= a[i-n];
		cur += a[i];
		mx = max(mx, cur);
	}

	// on the sides
	for (int i = 0; i < n; i++) {
		cur -= a[i+n];
		cur += a[i];
		mx = max(mx, cur);
	}
	return sum_all - mx;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	vector<int> a(2*n);
	for (int i = 0; i < 2*n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	vector<int> ans;
	int score = 0;
	do {
		int gg = eval(a, n);
		if (gg > score) {
			score = gg;
			ans = a;
		}
	} while (next_permutation(a.begin() + 1, a.end()));

	cerr << "Our score: " << score << '\n';
	for (int i: ans) cout << i << ' ';

	return 0;
}

