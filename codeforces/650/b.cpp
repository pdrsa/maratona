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
		for(int i = 0; i < n; i++) cin >> a[i];
		int np = 0, ni = 0;
		for(int i = 0; i < n; i++){
			if(a[i] % 2 == 1 and i % 2 == 0) ni++;
			if(a[i] % 2 == 0 and i % 2 == 1) np++;
		}
		if(np != ni) cout << -1 << endl;
		else cout << np << endl;
	}
	exit(0);
}
