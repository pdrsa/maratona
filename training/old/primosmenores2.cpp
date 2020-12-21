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
	vector<bool> pr(10000002, false);
	ll n; cin >> n;
	for(ll p = 2; p <= n; p++){
		if(!pr[p]){
			cout << p << " ";
			for(ll j = p * p; j <= n; j+=p){
				pr[j] = true;
			}
		}
	}
	exit(0);
}
