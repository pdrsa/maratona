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
		vector<int> a(n);
		bool ans = true;
		for(int i = 0; i < n; i++) cin >> a[i];
		sort(a.begin(), a.end());
		for(int i = 0; i < n - 1; i++){
			if(abs(a[i] - a[i+1]) > 1){
				ans = false;
				break;
			}
		}

		if(ans) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	exit(0);
}
