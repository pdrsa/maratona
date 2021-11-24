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
	int n; cin >> n;
	vector<pair<int, int>> v(n);
	
	int a = 0, tot = n;
	for(int i = 0; i < n; i++){
		auto &[x, y] = v[i];
		cin >> x >> y;
		if(x > y) a++;
	}
	
	vector<pair<int, int>> ans;
	for(int i = 0; i < n-1 and a <= (tot/2); i++){
		auto [x1, y1] = v[i];
		auto [x2, y2] = v[i+1];
		
		//If I win on both I shouldn't merge
		if(x1 > y1 and x2 > y2) continue;
		
		// I win after merge or I wasn't winning in either
		if((x1 + x2 > y1 + y2) or (y1 >= x1 and y2 >= x2)){
			tot--, i++;
			ans.pb({i, i+1});
		}
	}

	if(a <= (tot/2)) cout << -1 << endl;
	else{
		cout << ans.size() << endl;
		for(auto [x, y]: ans) cout << x << " " << y << endl;
	}

	exit(0);
}
