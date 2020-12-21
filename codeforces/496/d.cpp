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
	vector<int> t(s.size());
	for(int i = 0; i < s.size(); i++) t[i] = (s[i] - '0') % 3;

	int ans = 0;
	int n2 = 0, n1 = 0;
	for(int i = 0; i < s.size(); i++){
		if(t[i] == 0){
			ans++; n2 = 0; n1 = 0;
			continue;
		}
		
		if(t[i] == 1){
			if(n2 > 0 or n1 > 1){
				ans++; n2 = 0; n1 = 0;
			} else n1++;
		}

		if(t[i] == 2){
			if(n1 > 0 or n2 > 1){
				ans++; n2 = 0; n1 = 0;
			} else n2++;
		}
	}

	cout << ans << endl;
	exit(0);
}
