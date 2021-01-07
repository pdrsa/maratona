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
	vector<vector<ii>> points(1002);

	for(int i = 1; i <= n; i++){
		int x, y; cin >> x >> y;
		points[(y/1000)].pb({x,i});
	}
	
	for(int i = 0; i < 1002; i++){
		if(i % 2) sort(points[i].rbegin(), points[i].rend());
		else sort(points[i].begin(), points[i].end());
	}

	for(int i = 0; i < 1002; i++){
		for(auto [x, idx]: points[i]) cout << idx << " ";
	}

	cout << endl;
	
	exit(0);
}
