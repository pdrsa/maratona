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

int main(){ _
	int n; cin >> n;
	vector<ii> v(n);
	for(auto &[f, p]: v){
		cin >> p >> f;
	}
	sort(v.begin(), v.end());
	ll maxg = -INF, curg = 0;
	for(auto [f, p]: v){
		curg += p;
		maxg = max(maxg, curg-f);
	}
	cout << maxg << endl;
	exit(0);
}
