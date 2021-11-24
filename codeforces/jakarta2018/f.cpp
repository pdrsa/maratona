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

int32_t main(){ _
	ll n, m; cin >> n >> m;
	vector<ll> a(n), b(n);
	for(ll &i: a) cin >> i;
	for(ll &i: b) cin >> i;
	

	for(int i = 1; i < n; i++) a[i] += a[i-1];
	
	int solved = n-1;
	for(int i = 0; i < n; i++){
		if(a[i] > m){
			solved = i-1;
			break;
		}
	}

	if(solved == -1){
		cout << -1 << endl;
		exit(0);
	}


	vector<ll> big(solved+1);
	big[solved] = b[solved];
	for(int i = solved - 1; i >= 0; i--)
		big[i] = max(b[i], big[i+1]);

	vector<ll> pops;
	ll ballon = 0, ayu = 0, time = 0;

	int lastI;
	for(int i = 0; i <= solved; i++){
		time += b[i]; // Time wasted
		if(time > m) break;
		if(ayu < n and a[ayu] <= time) ayu++, ballon++;
		if(ballon > 0 and b[i] == big[i]){
			ballon--;      // Spend a ballon
			pops.pb(time); // Mark poppin time
			i--;           // Repeat this task
		}

		lastI = i;
	}
	// cout << "LastI: " << lastI  << " Solved:" << solved << endl;
	if(lastI < solved){
		cout << pops.size() << endl;
		for(int j: pops) cout << j << " ";
		cout << endl;
	} else cout << -1 << endl;
	exit(0);
}
