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
	int n; cin >> n;
	ll gcd;
	ll aux;
	
	cin >> gcd;

	for(int i = 1; i < n; i++){
		cin >> aux;
		gcd = __gcd(gcd, aux);
	}
	
	ll ans = 0;
	for(ll i = 1; i*i <= gcd; i++){
		if(gcd % i == 0){
			if(gcd/i == i) ans++;
			else ans += 2;
		}
	}

	cout << ans << endl;
	
	exit(0);
}
