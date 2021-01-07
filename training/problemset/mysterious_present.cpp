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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){ _
	int n, W, H; cin >> n >> W >> H;
	vector<tuple<int,int,int>> env;

	for(int i = 0; i < n; i++){
		int x, y; cin >> x >> y;
		if(x <= W or y <= H) continue;
		env.pb({x,y,i});
	}
	sort(env.begin(), env.end());
	
	//No envelopo fits
	if(env.size() == 0){
		cout << 0 << endl;
		exit(0);
	}

	vector<ii> dp(env.size());
	dp[0] = {1, -1};
	
	for(int i = 1; i < env.size(); i++){
		auto [x,y,z] = env[i];
		ii maxi = {0, -1};

		for(int j = 0; j < i; j++){
			auto [x2, y2, z2] = env[j];
			
			if(dp[j].f > maxi.f and x2 < x and y2 < y)
				maxi = {dp[j].f, j};
		}
		
		maxi.f++;
		dp[i] = maxi;
	}
	
	ii maxi = {0, -1};
	int maxidx = 0;

	for(int i = 0; i < dp.size(); i++){
		maxi = max(maxi, dp[i]);
		if(maxi == dp[i]) maxidx = i;
	}

	vector<int> ans; ans.pb(maxidx);
	cout << maxi.f << endl;
	while(maxi.s != -1){
		ans.pb(maxi.s); maxi = dp[maxi.s];
	}

	reverse(ans.begin(), ans.end());
	for(auto u: ans) cout << get<2>(env[u]) + 1 << " ";
	cout << endl;

	exit(0);
}
