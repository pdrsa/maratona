//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
// #define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int FIB = 75;

vector<ll> ans;
vector<ll> fib;

bool dfs(ll x, int idx){
	if(x == 1LL) return true;
	if(idx == -1) return false;

	for(int i = idx; i >= 0; i--){
		ll xx = x;
		int j = 0;
		while(xx % fib[i] == 0){
			xx /= fib[i]; j++;
		}
		for(; j > 0; j--){
			if(dfs(xx, i-1)){ // Found something
				while(j--)	ans.pb(i);
				return true;
			}
			xx *= fib[i];
		}
	}

	return false;
}

int32_t main(){ _
	ll n; cin >> n;
	if(n == 1){ cout << "B" << endl; exit(0); }
	fib.pb(2); fib.pb(3);
	for(int i = 2; i <= FIB; i++) fib.pb(fib[i-2] + fib[i-1]);
	dfs(n, FIB-1);
	reverse(ans.begin(), ans.end());
	if(ans.empty()){
		cout << "IMPOSSIBLE" << endl;
		exit(0);
	}
	for(int i: ans){
		i++;
		while(i--) cout << "A";
		cout << "B";
	} cout << endl;
	exit(0);
}
