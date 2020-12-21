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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
	int n; cin >> n; ll m; cin >> m;
	vector<ll> h(n); for(ll &i: h) cin >> i;
	ll sum = 0; ll maxi = 0;

	for(int l = 0, r = 0; r < n; ){
		while(sum + h[r] > m){
			sum -= h[l]; l++;
		}
		while(r < n and sum + h[r] <= m){
			sum += h[r]; r++;
		}
		maxi = max(sum, maxi);
	}
	cout << maxi << endl;
	exit(0);
}
