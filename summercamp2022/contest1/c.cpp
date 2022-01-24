// Time: (ubiratan, EduardoFernandes, pedrosa)
// pedrosa

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

vector<int> pos;
int n, c;

bool solve(int x){

	int cows = 1;
	int prev = pos[0];
	for(int i = 1; i < pos.size(); i++){
		
		// Put cow
		if(pos[i] - prev >= x){
			cows++; prev = pos[i];
		}
	}
	
	return cows >= c;
}

int32_t main(){ _
	int tt; cin >> tt;
	while(tt--){
		cin >> n >> c;
		pos.clear();
		while(n--){
			int a; cin >> a;
			pos.pb(a);
		}
		
		sort(pos.begin(), pos.end());
		int l = 0, r = INF;
		while(l < r){
			int mid = (l+r+1)/2;
			if(solve(mid)) l = mid;
			else r = mid-1;
		}

		cout << l << endl;
	}
	exit(0);
}
