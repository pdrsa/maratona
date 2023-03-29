#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define FOR(i,a,n) for(int i=a; i<n;i++)

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main() { _
	int n, g;
	cin >> n >> g;

	vector<vector<int>> grid(n, vector<int>(n));
	for (auto &v : grid)
		for (int &i : v)
			cin >> i;

	int k = __lg(n);

	for (int q = 0; q <= k; q++) {
		bool ok = true;
		int x = 1 << q;
		for (int i = 0; i < n; i += x) {
            for (int j = 0; i < n; i += x) {
                int cnt = 0;
                for (int a = 0; a < x; a++) {
                    for (int b = 0; b < x; b++) {
                        cnt += grid[i + a][j + b];	
                    }
                }
                ok &= cnt >= g;
            }
		}
		if (ok) {
			cout << n * n / x / x << endl;
			return 0;
		}
	}
    
    cout << 0 << endl;
}
