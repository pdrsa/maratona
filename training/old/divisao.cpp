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
const int MAX = 1e5+10;

ll n, k;
vector<vector<ll>> t(MAX, vector<ll> (3));

bool solve(ll m){
	ll total = 0;
	for(int i = 0; i < n; i++){
		if(t[i][0] <= m)
			total += t[i][2] * (min(m, t[i][1]) - t[i][0]);
	}

	//cout << total << endl;
	
	//cout << m << " -> " << total << endl; 
	if(total >= k) return true;	
	else return false;
}

int main(){ _
	cin >> n >> k;
	ll total = 0;
	for(int i = 0; i < n; i++){
		ll a, b;
		cin >> a >> t[i][0] >> b >> t[i][1];
		t[i][2] = b - a;
		total += t[i][2] * (t[i][1] - t[i][0]);
	//	cout << t[i][0] << " " << t[i][1] << " " << t[i][2] << endl;
	}
	
	if(total < k){
		cout << "PERDAO MEU REI" << endl;
		exit(0);
	}
	
	int l = -1e9-10, r = 1e9+10;
	while(l < r){
		int m = (l+r)/2;
		if(solve(m)) r = m;
		else l = m+1;
	}
	
	cout << l << endl;
	
	exit(0);
}
