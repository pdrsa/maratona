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

		for(int i = n-1; i > 0; i--){
			cout << i;
			if(b[i] != a[i]){
				if(a[0] == b[i]){
					ans.pb(1);
					a[0] = !a[0];
				}
				ans.pb(i+1);
				int r = i;
				for(int l = 0; l <= i/2; l++){
					bool aux = a[l];
					a[l] = !a[r];
					a[r] = !aux;
					r--;
				}
			}
		}
		cout << endl;
		if(a[0] != b[0]){
			ans.pb(1);
			a[0] = !a[0];
		}
		
		cout << ans.size() << " ";
		for(auto u: ans) cout << u << " ";
		cout << endl;
		//for(auto u: a) cout << u;
		//cout << endl;

	}
	exit(0);
}
