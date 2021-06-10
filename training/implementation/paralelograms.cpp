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
	vector<int> c(200001);
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int a; cin >> a;
		c[a]++;
	}
	int ans = 0;
	for(int i = 0; i <= 200000; i++){
		ans += c[i]/2;
	}
	cout << ans/2 << endl;
	exit(0);
}
