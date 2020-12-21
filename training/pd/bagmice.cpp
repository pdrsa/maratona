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
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<ld>> dp(1001, vector<ld>(1001, -1.0));

ld solve(int w, int b){
	if(w <= 0) return 0.0;
	if(b <= 0) return 1.0;
	
	int W = w, B = b;
	if(dp[w][b] != -1.0) return dp[w][b];
	
	ld ans = ((w*1.0)/(w+b));

	// chance of princess losing
	ld miss = ((b*1.0)/(w+b));
	b--;
	// chance of dragon losing
	miss *= ((b*1.0)/(w+b));
	b--;
	
	// if chance of dragon losing is zero then we stop? idk
	if(miss > 1e-14){
		// black jumps
		ld missblack = solve(w,b-1) * ((b*1.0)/(w+b));
		// white jumps
		ld misswhite = solve(w-1,b) * ((w*1.0)/(w+b));
		
		ans += (missblack + misswhite) * miss;
	}
	
	return dp[W][B] = ans;
}

int main(){ _
	int w, b; cin >> w >> b;
	cout << fixed << setprecision(9);
	
	cout << solve(w, b) << endl;
	
	exit(0);
}
