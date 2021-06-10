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
		vector<bool> ap(26);
		bool safe = true;
		for(int i = 0; i < s.size(); i++){
			int idx = int(s[i] - 'A');
			if(i and s[i] != s[i-1] and ap[idx]) safe = false;
			ap[idx] = true;
		}

		if(safe) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	exit(0);
}
