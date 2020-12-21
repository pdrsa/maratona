#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
	vector<vector<int>> b(31);
	for (int i = 0; i < 31; i++) b[i] = {0, 0};
	int n; cin >> n;
	int a; char c;
	for (int i = 0; i < n; i++){
		cin >> a >> c;
		a = a-30;
		if (c == 'E'){
			b[a][0]++;
		}
		else b[a][1]++;
	}

	int ans = 0;
	for (int i = 0; i < 31; i++){
		ans += min(b[i][0], b[i][1]);
	}

	cout << ans << endl;
	exit(0);
}
