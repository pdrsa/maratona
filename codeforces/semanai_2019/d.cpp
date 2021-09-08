#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { //_
	#warning fast io

	int n, k;
	cin >> n >> k;
	vector<int> on(n, 1);
	int pos = k - 1;

	vector<int> ans;
	for (int i = 0; i < n-1; i++) {
		int j = pos; 
		int jumpou = 0;

		while (true) {	
			if (on[j]) {
				jumpou++;
				if (jumpou == k) {
					on[j] = 0;
					ans.push_back(j + 1);
				}
				else if (jumpou == k + 1) {
					pos = j;
					break;
				}
			}
			j = (j + 1) % n;
		}

		for (int vi : on) cout << vi << ' ';
		cout << endl;
	}
	cout << endl;
	for (int i : ans) cout << i << ' ';
	cout << endl;

	exit(0);
}
