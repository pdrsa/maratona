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
const int MAX = 1e5 + 50;
vector<int> c(MAX);
vector<pair<int, int>> v(MAX);

int32_t main(){ _
	int n, k; cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> v[i].first >> v[i].second;
		c[v[i].first] = v[i].second;
	}
	bool ok = true;
	for(int i = 1; i <= n; i++)
		if(c[i] != v[i].second) ok = false;

	cout << (ok ? "Y" : "N") << endl;
	exit(0);
}
