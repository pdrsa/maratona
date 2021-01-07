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
	vector<int> a(n); for(int &i: a) cin >> i;

	vector<int> front(n);
	vector<int> back(n);

	front[0] = 1;
	back[n-1] = 1;

	for(int i = 1; i < n; i++) front[i] = min(a[i], front[i-1] + 1);
	for(int i = n-2; i >= 0; i--) back[i] = min(a[i], back[i+1] + 1);

	int ans = 1;
	for(int i = 0; i < n; i++) ans = max(ans, min(front[i], back[i]));

	cout << ans << endl;

	exit(0);
}
