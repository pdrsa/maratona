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
	int tt; cin >> tt;
	while(tt--){
		ll x, y, z; cin >> x >> y >> z;
		ll c = 0;
		ll d;
		ll maior = max(x,max(y,z));
		if(max(x,max(y,z)) == x ) c++;
		else d = x;
		if(max(x,max(y,z)) == y ) c++;
		else d = y;
		if(max(x,max(y,z)) == z ) c++;
		else d = z;
		if(c < 2) cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			if(c == 3) cout << maior << " " << maior << " " << maior << endl;
			else cout << max(x,max(y,z)) << " " << d << " " << d << endl;
		}
	}
	exit(0);
}
