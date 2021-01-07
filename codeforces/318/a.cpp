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
	int v; cin >> v;
	vector<int> a(n-1); for(int &i:a) cin >> i;
	sort(a.begin(), a.end());
	int ans = v;
	reverse(a.begin(), a.end());
	
	while(a[0] >= ans){
		ans++; a[0]--;
		sort(a.begin(), a.end());
		reverse(a.begin(), a.end());
	}

	cout << ans - v << endl;
	exit(0);
}
