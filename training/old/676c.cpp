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
	int n, fk; cin >> n >> fk;
	string s; cin >> s;
	int l = 0, r = 0;
	int ans = 0;
	int k = fk;
	while(r < n){
		if(k >= 0){
			if(s[r] == 'a') k--;
			r++;
		}
		if(k < 0){
			if(s[l] == 'a') k++;
			l++;
		}
		ans = max(ans, r-l);
	}
	
	r = 0; l = 0;
	k = fk;
	while(r < n){
		if(k >= 0){
			if(s[r] == 'b') k--;
			r++;
		}
		if(k < 0){
			if(s[l] == 'b') k++;
			l++;
		}
		ans = max(ans, r-l);
	}

	cout << ans << endl;
	exit(0);
}
