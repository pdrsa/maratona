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
	int tt; cin >> tt;
	while(tt--){
		string s; cin >> s;
		vector<int> p(3);
		for(int i = 0; i < s.size(); i++){
			if(s[i] == 'R') p[0]++;
			if(s[i] == 'P') p[1]++;
			if(s[i] == 'S') p[2]++;
		}
		int z = max({p[0], p[1], p[2]});
		char ans;
		if (z == p[0]) ans = 'P';
		if (z == p[1]) ans = 'S';
		if (z == p[2]) ans = 'R';
		for(int i = 0; i < s.size(); i++) cout << ans;
		cout << endl;
	}
	exit(0);
}
