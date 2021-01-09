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
	vector<int> t(3);
	int n; cin >> n;
	while(n--){
		int a, b, c; cin >> a >> b >> c;
		t[0] += a; t[1] +=b; t[2] += c;
	}
	if(t[0] != 0 or t[1] != 0 or t[2] != 0) cout << "NO" << endl;
	else cout << "YES" << endl;
	exit(0);
}
