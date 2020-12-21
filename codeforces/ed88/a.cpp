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
	int t; cin >> t;
	while(t--){
		int n, m, k; cin >> n >> m >> k;
		int c = n/k;
		if(m <= c){
			cout << m << endl;
			continue;
		}
		int o = m-c;
		o = o % (k-1) == 0 ? o/(k-1) : o/(k-1) + 1;
		cout << c - o << endl;
	}
	exit(0);
}
