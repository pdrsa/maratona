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
	int q; cin >> q;
	while(q--){
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		bool flag1 = true;
		bool flag2 = true;
		for (int i = 0; i < n-1; i++){

			if (a[i] != a[i+1] - 1){
				if (a[i] != n or a[i+1] != 1){
					flag1 = false;
				}
			}

			if (a[i] != a[i+1] + 1){
				if(a[i] != 1 or a[i+1] != n){
					flag2 = false;
				}
			}
		}

		if (flag1 or flag2) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	exit(0);
}
