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

int main(){ _
	int n; cin >> n;
	vector<int> s(n); for(int &i:s) cin >> i;
	string ab; cin >> ab;
	vector<ll> sum(n);
	sum[0] = ((ab[0] == 'B') ? s[0] : 0);
	for(int i = 1; i < n; i++) sum[i] = sum[i-1] + ((ab[i] == 'B') ? s[i] : 0);
	
	ll maxi = sum[n-1];
	ll cur = 0;

	for(int i = 0; i < n; i++){
		if(ab[i] == 'A') cur += s[i];
		//else cur -= s[i];

		ll pref = sum[n-1] - sum[i];
		maxi = max(cur + pref, maxi);
	}
	
	cur = 0;
	for(int i = n-1; i >= 0; i--){
		if(ab[i] == 'A') cur += s[i];
		//else cur -= s[i];

		ll pref = (i ? sum[i-1] : 0);
		maxi = max(cur + pref, maxi);
	}

	cout << maxi << endl;
	exit(0);
}
