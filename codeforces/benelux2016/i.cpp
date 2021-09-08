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
const int MAX = 1e6;

int divi[MAX];
vector<int> primes;

void crivo(int lim) {
	divi[1] = 1;
	for (int i = 2; i <= lim; i++) {
		if (divi[i] == 0) divi[i] = i, primes.push_back(i);
		for (int j : primes) {
			if (j > divi[i] or i*j > lim) break;
			divi[i*j] = j;
		}
	}
}

int main(){ _
	int q; cin >> q;
	
	bool primo = true;
	// Checa se Q é primo
	for(int i = 2; i*i <= q; i++){
		if(q % i == 0){
			primo = false;
			break;
		}
	}

	if(primo and q > 1){
		cout << "yes" << endl;
		exit(0);
	}

	int sq = -INF;
	for(int i = 1; i*i <= q; i++) sq = i;
	crivo(sq);

	for(int p: primes){
		for(int k = p; k <= q; k*= p){
			if(k == q){
				cout << "yes" << endl;
				exit(0);
			}
		}
	}

	cout << "no" << endl;
	
	exit(0);
}
