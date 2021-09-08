#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
	
	int n;
	cin >> n;
	vector<int> v(2 * n);
	for (int& vi : v) cin >> vi;

	vector<int> perm(2 * n - 1);
	iota(perm.begin(), perm.end(), 0);
	
	int best = INF;
	vector<int> vans(2 * n, -1), v2(2 * n);
	v2[2 * n - 1] = v[2 * n - 1];

	do {
		int curbest = 0, sum = 0;
		for (int i = 0; i < 2 * n - 1; i++) v2[i] = v[perm[i]];

		for (int i = 0; i < n; i++) sum += v2[i];
		for (int i = 0; i < 2 * n; i++) {
			curbest = max(curbest, sum);
			sum = sum - v2[i] + v2[(i + n) % (2 * n)];
		}
		if (curbest < best) best = curbest, vans = v2;
		
	} while (next_permutation(perm.begin(), perm.end()));
	
	for (int vi : vans) cout << vi << ' ';
	cout << endl;

	exit(0);
}
