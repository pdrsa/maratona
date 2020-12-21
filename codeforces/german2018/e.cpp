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

const int MAX = 10000001;
bool prime[MAX];

void sieve() 
{ 
    memset(prime, true, sizeof(prime)); 
	prime[1] = false;
  
    for (int p=2; p*p < MAX; p++) 
    { 
        if (prime[p] == true) 
        { 
            for(int i=p*p; i < MAX; i += p) 
                prime[i] = false; 
        }
    }
} 

int main(){ _
	sieve();
	double a, b;
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		a *= 100000; b*= 100000;
		a += 0.000001; b+= 0.000001;
		int c, d;
		c = int(a); d = int(b);
		if (c == d){
			cout << 2 << " " << 2 << endl;
			continue;
		}
		int mdc = __gcd(c,d);
		c = c/mdc; d = d/mdc;
		if(prime[c] and prime[d]){
			cout << c << " " << d << endl;
		}
		else cout << "impossible" << endl;
	}

	exit(0);
}
