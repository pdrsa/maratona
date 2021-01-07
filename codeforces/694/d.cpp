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
const int MAX = 1e6 + 5;

vector<bool> prime(MAX, true);
vector<ll> primes;

void sieve() { 
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

int main(){ _
	sieve();

	int tt; cin >> tt;

	while(tt--){
		int n; cin >> n;
		vector<ll> a(n);

		for(ll &i:a){
			cin >> i;
			for(auto p: primes){
				if(p*p > i) break;
				while(i % (p*p) == 0) i = i/(p*p);
			}
		}

		sort(a.begin(), a.end());

		int c = 1, par = 0, maxi = 0;
		int n1 = (a[0] == 1 ? 1 : 0);
		for(int i = 1; i < n; i++){
			if(a[i] == 1) n1++;

			else if(a[i] == a[i-1]) c++;
			
			else{
				if(c % 2 == 0) par += c;
				maxi = max(maxi, c);
				c = 1;
			}
		}

		if(c % 2 == 0) par += c;
		maxi = max(maxi, c);
		
		int q; cin >> q;
		while(q--){
			ll t; cin >> t;
			if(t == 0) cout << max(maxi, n1) << endl;
			else cout << max(par+n1, maxi) << endl;
		}
	}
	exit(0);
}
