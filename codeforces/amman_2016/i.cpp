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


int solve(vector<int> p, int k){
	int mini = 0, maxi = 0, ans = 0, pos = 0;
	for(int i: p){
		pos += i;
		mini = min(mini, pos);
		maxi = max(maxi, pos);
		if(pos >= k) ans++;
		if(pos < 0 and (maxi - mini >= k)) ans++;
	}
	return ans;
}

int32_t main(){ _
	int tt; cin >> tt;
	while(tt--){
		vector<int> h, v;
		int r, c; cin >> r >> c;
		string s; cin >> s;
		for(char ch: s){
			if(ch == '>') h.pb(+1);
			else if(ch == '<') h.pb(-1);
			else if(ch == 'v') v.pb(-1);
			else v.pb(+1);
		}
		
		cout << solve(h, c) + solve(v, r) << endl;
	}
	exit(0);
}

