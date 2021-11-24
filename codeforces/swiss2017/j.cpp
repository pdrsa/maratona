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

int32_t main(){_
	int n; cin >> n;
	vector<pair<ll, ll>> v(n);
	
	for(int I=0; I<n; I++){
		cin >> v[I].first >> v[I].second;
        v[I].second++; // Get 1 based height
	}
	sort(v.begin(), v.end());
	
	vector<ll> suf(n+1);
	
	suf[n-1] = v[n-1].second;
	for(int i = n - 2; i >= 0; i--) suf[i] = max(suf[i+1], v[i].second);
	
	ll circ = abs((v[0].first - 1) - (v[n-1].first + 1)) + 1 // Horizontal length
	+ 2*(suf[0] + 1); // Two times vertical length
	
	ll area = 0;
	ll lx = v[0].first - 1, ly = 0;
	
	bool right = false;
	for(int i = 0; i < n; i++){
		ll nx;

		if(right) nx = v[i].first + 1; // Surrounding to the right
		else      nx = v[i].first - 1; // Surrounding to the left
		area += ly * (nx - lx); // Update Area
        //cout << "ly=" << ly << ", nx=" << nx << ", lx=" << lx << endl;
        //cout << "Adicionou area " << ly * (nx - lx) << " no cara " << i << endl;

		if(v[i].second == suf[i] and !right){ // Maximum height
            //cout << "Adicionou area " << v[i].second << " no cara " << i << endl;
			area += v[i].second; // Add one times height
			right = true;
			nx    = v[i].first + 1;
		}

		ly = max(v[i].second, ly); // We go up if we have to go up
		ly = min(ly, suf[i+1]);     // We go down if we can go down
        lx = nx; // Update previous values
	}
	cout << circ << " " << circ - 2 << " " << area << endl;
	exit(0);
}
