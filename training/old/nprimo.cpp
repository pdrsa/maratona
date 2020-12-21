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
	vector<bool> pr(20000002, false);
	ll n; cin >> n;
	ll p;
	for(p = 2;; p++){
		if(!pr[p]){
			n--;
			if (n == 0) break;
			for(ll j = p * p; j < 20000002; j+=p){
				pr[j] = true;
			}
		}
	}
	cout << p << endl;
	exit(0);
}
