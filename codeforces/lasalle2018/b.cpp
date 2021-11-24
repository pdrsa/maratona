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
	
	vector<tuple<int, int, int>> cop;
	for(int x = 1; x < 500; x++)
		for(int y = 0; y < 500; y++)
			if(__gcd(x+y, y) == 1) cop.pb({x+y, x, y});
	
	sort(cop.rbegin(), cop.rend());
	ll h; cin >> h;
	h++;
	vector<tuple<int, int, int>> ans;

	while(1){
		auto [s, x, y] = cop.back();
		if(s <= h) ans.pb({y/x, x, y});
		else break;
		cop.pop_back();
		h -= s;
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	vector<int> fans;

	int beg = INF;
	for(auto [bla, x, y]: ans){
		for(int i = 0; i < y; i++){
			beg--;
			fans.pb(beg);
		}
		for(int i = 0; i < x; i++) fans.pb(beg);
	}

	int mini = INF;
	for(auto i: fans) mini = min(mini, i);
	for(int &i: fans) i -= mini;
	cout << *max_element(fans.begin(), fans.end()) << " ";
	for(int i: fans) cout << i << " ";
	cout << endl;
	exit(0);
}
