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
	string s; cin >> s;
	ll ans = 0;
	for(int i = s.size() - 1; i >= 0; i--){
		
		if(s[i] == '0' or s[i] == '4' or s[i] == '8') ans++;
		
		if(i == 0) continue;

		if(s[i] == '2' or s[i] == '6')
			if(s[i-1] == '1' or s[i-1] == '3' or s[i-1] == '5' or
			s[i-1] == '7' or s[i-1] == '9')
				ans += i;
		
		if(s[i] == '0' or s[i] == '4' or s[i] == '8')
			if(s[i-1] == '0' or s[i-1] == '2' or s[i-1] == '4'
			or s[i-1] == '6' or s[i-1] == '8')
				ans += i;
	}

	cout << ans << endl;
	exit(0);
}
