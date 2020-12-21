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
	int a,b,c; cin >> c >> a >> b;
	ii ans = {0,0};
	for(int i = 0; i * a <= c; i++){
		int r =  c - (i*a);
		if(r % b == 0){
			ans = {i, (r/b)};
			break;
		}
	}
	if(ans.f != 0 or ans.s != 0) cout << "YES" << endl << ans.f << " " << ans.s << endl;
	else cout << "NO" << endl;
	exit(0);
}
