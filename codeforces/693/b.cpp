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
		int g1 = 0, g2 = 0;
		while(n--){
			int aux; cin >> aux;
			if(aux == 1) g1++;
			else g2++;
		}
		
		int b = g2/2;

		int a = (g2+1)/2;

		b *= 2; a *= 2;

		
		g1 -= (abs(b-a));

		if(g1 >= 0 and g1 % 2 == 0) cout << "YES" << endl;
		else cout << "NO" << endl;

	}
	exit(0);
}
