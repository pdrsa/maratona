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
		string s; cin >> s;
		vector<int> f(26);
		for(char c: s) f[c - 'a']++;
		sort(f.rbegin(), f.rend());
		
		int c1 = 0, c2 = 0;

		for(int a: f){
			if(c1 <= c2) c1 += a;
			else c2 += a;
		}

		cout << min(c1, c2) << endl;
	}
	exit(0);
}
