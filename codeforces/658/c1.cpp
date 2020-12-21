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
		int n; cin >> n;
		vector<bool> a(n);
		vector<bool> b(n);
		string s; cin >> s;
		for(int i = 0; i < n; i++) if(s[i] == '1') a[i] = true;
		cin >> s;
		for(int i = 0; i < n; i++) if(s[i] == '1') b[i] = true;
		vector<int> ans;
		
		int c = 0, i = n-1, p = 0;
		bool r = false;
		while(c < n){
			cout << i;
			if((b[n-c-1] != a[i] and !r) or (b[n-c-1] == a[i] and r)){
				if((a[p] == b[n-c-1] and !r) or (a[p] != b[n-c-1] and r))
					ans.pb(1);
				ans.pb(n-c);
				r = !r;
				swap(i,p);
			}
			if(r) i++;
			else i--;

			c++;
		}
	//	if(a[0] != b[0]){
	//		ans.pb(1);
	//		a[0] = !a[0];
	//	}
		cout << endl;
		cout << ans.size() << " ";
		for(auto u: ans) cout << u << " ";
		cout << endl;
		//for(auto u: a) cout << u;
		//cout << endl;

	}
	exit(0);
}
