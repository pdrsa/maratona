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
	int t; cin >> t;
	while(t--){
		ll n, k; cin >> n >> k;
		ll aux, me, ma, act;
		k--;
		while (k--){
			aux = n;
			me = INF; ma = 0;
			while(aux > 0){
				act = aux % 10;
				me = min(me, act);
				ma = max(ma, act);
				aux = aux / 10;
			}
			if (me == 0 or ma == 0) break;
			n += (me*ma);
		}

		cout << n << endl;
	}
	exit(0);
}
