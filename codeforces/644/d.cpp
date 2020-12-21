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
		ll menor;
		for (ll i = 1; i * i <= n and i <= k; i++){
			if (n % i == 0){
				menor = n/i;
				if((n/i) <= k){
					menor = i;
					break;
				}
			}
		}
		cout << menor << endl;
	}
	exit(0);
}
