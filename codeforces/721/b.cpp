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
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		string s; cin >> s;
		int n0 = 0;
		for(char c: s) if(c == '0') n0++;
		if(n % 2 == 1 and n0 > 2 and s[n/2] == '0') cout << "ALICE" << endl;
		else cout << "BOB" << endl;
	}
	exit(0);
}
