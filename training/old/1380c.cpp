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
		int n, k; cin >> n >> k;
		vector<int> c(n);
		for(int i = 0; i < n; i++){
			cin >> c[i];
		}
		sort(c.begin(), c.end(), greater<int>());
		int ans = 0, mp = 1, mini = 1000000000;
		for(int i = 0; i < n; i++){
			mini = min(mini, c[i]);
			if(mp * mini >= k){
				mp = 1;
				mini = 1000000000;
				ans++;
			}
			else mp++;
		}

		cout << ans << endl;
	}
	exit(0);
}
