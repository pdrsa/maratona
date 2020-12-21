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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		vector<int> c(n, 1);
		vector<bool> h(n, false);
		vector<int> a(n);
		for(int &i:a){
			cin >> i; i--;
			h[i] = true;
		}

		for(int i = 1; i < n; i++){
			if(a[i] != a[i-1]) c[a[i]]++;
		}

		c[a[n-1]]--;
		int ans = INF;
		for(int i = 0; i < n; i++){
			if(h[i]){
				//cout << i << " = " << c[i] << endl;
				ans = min(c[i], ans);
			}
		}

		cout << ans << endl;
	}
	exit(0);
}
