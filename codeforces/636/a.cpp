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
	int n;
	cin >> n;
	for (int a = 0; a < n; a++){
		ll q;
		ll m = 3;
		ll t = 4;
		cin >> q;
		while(1){
			if (q % m == 0){
				cout << q/m << endl;
				break;
			}
			m = m + t;
			t = t*2;
		}
	}
	exit(0);
}
