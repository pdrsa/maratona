#include <iostream> 
typedef long long ll;
using namespace std; 

ll numberOfPaths(ll m, ll n) 
{ 
    ll path = 1; 
    for (ll i = n; i < (m + n - 1); i++) { 
        path *= i; 
        path /= (i - n + 1); 
    } 
    return path; 
} 
  
int main() 
{ 
	ll n, m; cin >> n >> m;
    cout << numberOfPaths(n, m); 
    return 0; 
} 
