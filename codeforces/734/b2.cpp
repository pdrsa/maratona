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
		int n, k; cin >> n >> k;
		vector<int> s(n); for(int &i: s) cin >> i;
		vector<int> f(n+10);
		for(int c: s) f[c]++;
		//sort(f.rbegin(), f.rend());
	
		vector<vector<int>> print(n+10);
		int lc = 0; // LC not used
		

		for(int j = 0; j < n + 10; j++)if(f[j] > 0){
			int a = f[j];
			if(a >= k){
				for(int i = 0; i < k; i++) print[j].pb(i);
			}
			else{
				int last = min(k, lc + a); // Menor que n
				for(int i = lc; i < last; i++) print[j].pb(i);
				if(lc + a >= k){
					lc = (lc + a) % k;
					for(int i = 0; i < lc; i++) print[j].pb(i);
				} else lc = last;
			}
		}
		

		// Now to print

		vector<int> ans;
		for(int p: s){
			if(print[p].empty()) ans.pb(0);
			else{
				ans.pb(print[p].back() + 1);
				print[p].pop_back();
			}
		}

		f.assign(k+1, 0);
		for(int i: ans) if(i > 0) f[i]++;
		
		int mini = INF;

		for(int i = 1; i < k+1; i++) mini = min(mini, f[i]);

		//cout << mini << endl;
		vector<int> count(k+1);
		// for(int i: ans) cout << i << " ";
		// cout << endl;

		for(int i = 0; i < n; i++){
			if(count[ans[i]] >= mini) cout << 0 << " ";
			else{
				count[ans[i]]++;
				cout << ans[i] << " ";
			}
		}

		cout << endl;
	}
	exit(0);
}
