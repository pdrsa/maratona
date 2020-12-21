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

int solve(string s, char c, int len){
	if(len == 1){
		if(s[0] == c) return 0;
		else return 1;
	}

	int r1 = 0, r2 = 0;
	for(int i = 0; i < len/2; i++)
		if(s[i] != c) r1++;
	for(int i = len/2; i < len; i++)
		if(s[i] != c) r2++;
	
	//if(r2 < r1) return r2 + solve(s.substr(0, len/2), c+1, len/2);
	//else if (r1 < r2) return r1 + solve(s.substr(len/2, len/2), c+1, len/2);
	int a1, a2;
	a1 = solve(s.substr(len/2, len/2), c+1, len/2);
	a2 = solve(s.substr(0, len/2), c+1, len/2);
	
	return(min(r1+a1, r2+a2));
}

int main(){ _
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		string s; cin >> s;
		cout << solve(s, 'a', n) << endl;
	}
	exit(0);
}
