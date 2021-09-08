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
const int MAX = 10000001; //10e7 (Just to illustrate)

bool prime[MAX];
vector<int> primes;

void sieve()
{
    memset(prime, true, sizeof(prime));
	prime[1] = false;

    for (int p=2; p*p < MAX; p++)
    {
        if (prime[p] == true)
        {
			//Everything less than p^2 has already been marked
            for(int i=p*p; i < MAX; i += p)
                prime[i] = false;
        }
    }

	for(int p=2;p < MAX; p++)
		if(prime[p]) primes.pb(p);
}

void count(vector<int> &v, int l, int r){
	// Calc A
	for(int p: primes){
		int t = p, exp = 1;
		
		while(t < l){
			t *= p; exp++;
		}

		// it = primeiro multiplo de p > l
		int it = (((t-1)/p)+1) * p;
		if(it != t){
			// Quantos caras tem de l até t
			int last = min(r, t);
			int nM   = (last - it)/p + 1;
			v[p]    += nM * (exp-1);
		}

		while(t <= r){
			int last = min(t*p, r); // Ultimo cara da iteração
			int nM   = (last - t)/p; // Numero de Vezes
			v[p]     += nM * exp;
			exp++; t *= p;
		}
	}
}

int main(){ _
	sieve();
	int tt; cin >> tt;
	while(tt--){
		int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
		vector<int> a(MAX), b(MAX);
		count(a, l1, r1), count(b, l2, r2);
		bool ans = true;
		for(int i = 0; i < MAX; i++) if(a[i] > b[i]) ans = false;
		cout << (ans ? "Yes" : "No") << endl;
	}
	exit(0);
}
