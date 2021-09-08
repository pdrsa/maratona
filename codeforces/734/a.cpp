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
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		int c = (n/3);
		if(n % 3 == 0) cout << c << " " << c << endl;
		if(n % 3 == 1) cout << c+1 << " " << c << endl;
		if(n % 3 == 2) cout << c << " " << c+1 << endl;
	}
	exit(0);
}
