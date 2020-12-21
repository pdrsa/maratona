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
		vector<ii> a(n);
		for(int i = 0; i < n; i++){
			int z; cin >> z; z--;
			if(a[z].f == 0) a[z].s = i;
			a[z].f++;
		}
		int ans = -1;
		for(int i = 0; i < n; i++){
			if(a[i].f == 1){
				ans = a[i].s + 1;
				break;
			}
		}
		cout << ans << endl;
	}
	exit(0);
}
