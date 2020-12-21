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
		vector<ii> z;
		int a, b;
		for(int i = 0; i < n; i++){
			cin >> a >> b;
			z.pb({0,a}); z.pb({1,b});
		}
		sort(z.begin(), z.end());
		for(auto u: z) cout << u.f << " " << u.s << endl;
		cout << endl << endl;
	}
	exit(0);
}
