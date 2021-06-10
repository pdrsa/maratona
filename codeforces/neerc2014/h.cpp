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

vector<vector<int>> dp(26, vector<int>(5002, -1));

int n;
string s;
string fans = "#";

int solve(char c, int i, string ans){
	if(c >= char('a' + n) or c < 'a') return 0;
	
	int z = c - 'a';
	if(i == s.size()){
		fans = ans;
		return 1;
	}
	

	if(dp[z][i] != -1) return dp[z][i];
	
	string temp;

	if(s[i] == '='){
		temp = ans;
		temp.pb(c);
		return dp[z][i] = solve(c, i+1, temp);
	}
	
	if(s[i] == '<'){
		for(char cc = c+1; cc < char('a' + n); cc++){
			temp = ans;
			temp.pb(cc);
			if(solve(cc, i+1, temp)) return dp[z][i] = 1;
		}
	}

	else{
		for(char cc = c-1; cc >= 'a'; cc--){
			temp = ans;
			temp.pb(cc);
			if(solve(cc, i+1, temp)) return dp[z][i] = 1;
		}
	}

	return dp[z][i] = 0;
}

int main(){ _

	cin >> n;
	cin >> s;
	
	string ans;

	for(char i = 'a'; i < char('a' + n); i++){
		string tt;
		tt.pb(i);
		//cout << tt << endl;
		solve(i, 0, tt);
		if(fans != "#"){
			cout << fans << endl;
			exit(0);
		}
	}
	cout << -1 << endl;
	exit(0);
}
