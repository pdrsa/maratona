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
	set<ii> l;
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++){
		int t, a, b; cin >> t >> a >> b;
		if (t == 1){
			l.insert({a,b});	
		}
		else{
			if (l.count({a,b}) or l.count({b,a})) cout << 1 << endl;
			else cout << 0 << endl;
		}
	}
	exit(0);
}
