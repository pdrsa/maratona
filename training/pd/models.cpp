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

int n;
vector<int> pd;
vector<int> s;

int solve(int i){
	if(pd[i] != -1) return pd[i];
	
	int ans = 1;

	for(int j = i+i; j <= n; j+=i){
		if(s[j] > s[i])
			ans = max(ans, solve(j)+1);
	}

	return pd[i] = ans;
}

int main(){ _
	int tt; cin >> tt;
	while(tt--){
		cin >> n;
		pd = vector<int>(n+1, -1);
		s = vector<int>(n+1); s[0] = -INF;
		for(int i = 1; i < n+1; i++) cin >> s[i];
		int ans = 0;
		for(int i = 1; i <= n; i++)
			ans = max(ans, solve(i));
		cout << ans << endl;
	}
	exit(0);
}
