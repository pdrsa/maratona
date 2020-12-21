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
		int minc = INF, mino = INF;
		vector<int> c(n);
		vector<int> o(n);
		for(int i = 0; i < n; i++){
			cin >> c[i];
			minc = min(minc, c[i]);
		}
		for(int i = 0; i < n; i++){
			cin >> o[i];
			mino = min(mino, o[i]);
		}

		ll ans = 0;
		for(int i = 0; i < n; i++){
			ans += max(c[i] - minc, o[i] - mino);
		}

		cout << ans << endl;
	}
	exit(0);
}
