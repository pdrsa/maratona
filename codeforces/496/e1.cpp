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
	ll n, m; cin >> n >> m;
	ll pm;
	vector<ll> p(n);
	
	for(int i = 0; i < n; i++){
		cin >> p[i]; if(p[i] == m) pm = i;
	}
	
	map<ll, ll> tr;
	
	ll ans = 0;
	
	ll mai = 0;
	for(int r = pm+1; r < n; r++){
		if(p[r] > m) mai++;
		else mai--;
		
		if(tr.count(mai))
			tr[mai]++;

		else tr[mai] = 1;
	}
	
	ll pr = 0;
	ll men = 0;
	for(int l = pm-1; l >= 0; l--){
		if(p[l] < m) men++;
		else men--;
		
		if(tr.count(men))
			ans += tr[men];

		if(tr.count(men+1))
			ans += tr[men+1];

		if(men == 0 or men == -1) ans++;
	}
	
	ans += tr[0];
	ans += tr[1];

	cout << ans+1 << endl;
	
	exit(0);
}
