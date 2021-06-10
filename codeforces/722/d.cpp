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
const ll MOD  = 998244353;
const ll MAX  = 1e6 + 10;

int divi[MAX];

void crivo(int lim) {
	for (int i = 1; i <= lim; i++) divi[i] = 1;

	for (int i = 2; i <= lim; i++)
		for (int j = i; j <= lim; j += i) {
			// para numero de divisores
			divi[j]++;
		}
}

int main(){ _
	int n; cin >> n;
	crivo(n+1);
	ll sum = 0;

	for(int i = 1; i < n; i++){
		sum *= 2;
		sum += divi[i];
		sum %= MOD;
	}
	
	cout << sum + divi[n] << endl;
	exit(0);
}
