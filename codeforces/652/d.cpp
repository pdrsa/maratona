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
const int MAX = 2000005;
const ll MOD  = 1000000007;
int main(){ _
	vector<ll> ans(MAX);
	vector<ll> pot(MAX);
	pot[3] = 1;
	for(int i = 5; i < MAX; i+=2){
		pot[i] = (pot[i-2] * 3) % MOD;
	}

	ans[3] = 1;
	for(int i = 4; i < MAX; i++){
		if(i % 2 == 0){
			ans[i] = (pot[i-1] + ans[i-3]) % MOD;
		}
		else{
			ans[i] = (pot[i] + ans[i-4]) % MOD;
		}
	}
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		cout << (ans[n] * 4) % MOD << endl;
	}
	exit(0);
}
