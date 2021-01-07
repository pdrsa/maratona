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
typedef pair<ll,ll> iill;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<int> p;

int find(int x){
	return p[x] = (x == p[x] ? x : find(p[x]));
}

int main(){ _
	int n, m; cin >> n >> m;
	p = vector<int> (n+2);
	for(int i = 1; i <= n+1; i++) p[i] = i;
	while(m--){
		char c; cin >> c;
		int x; cin >> x;
		if(c == '-') p[find(x)] = find(x+1);
		else cout << (find(x) == n+1 ? -1 : find(x)) << endl;
	}
	exit(0);
}
