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

vector<int> primes;
//set<int> bla;

int ev(int a, int b){
	int c = 1;
	for (int i = 0; i < b; i++) c *= a;
	return c;
}

void crivo(int n){
	bool prime[n+1];
	memset(prime, true, sizeof prime);
	for (int i = 2; i*i <= n; i++){
		if(prime[i]){
			for (int j = i*i; j <= n; j+=i) prime[j] = false;
		}
	}
	for (int i = 2; i <= n; i++)
		if (prime[i]) primes.pb(i);
}

int main(){ _
	int n; cin >> n;
	crivo(200000);
	int maior = 0;
	vector<int> a(n);

	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (a[i] > maior) maior = a[i];
	}
	
	ll ans = 1;
	for (auto p:primes){
		int cont = 0;
		int m1   = INF;
		int m2   = INF;
		if (p > maior) break;

		for (auto k:a){
			int pot = 0;
			if (cont > 1) break;
			
			while(k % p == 0){
				k = k/p;
				pot++;
			}

			if (pot == 0){
				cont++;
				continue;
			}

			if (pot < m2){
				if (pot < m1){
					m2 = m1;
					m1 = pot;
				}
				else{
					m2 = pot;
				}
			}
		}
		if (cont == 1) ans *= ev(p,m1);
		if (cont == 0) ans *= ev(p,m2);
	}

	cout << ans << endl;

	exit(0);
}
