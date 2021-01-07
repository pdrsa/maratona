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
	int n; cin >> n;
	p = vector<int> (n+2);
	for(int i = 1; i <= n; i++) p[i] = i; p[n+1] = 1;
	for(int i = 1; i <= n; i++){
		int x; cin >> x;
		cout << find(x) << " ";
		p[find(x)] = find(find(x) + 1);
	}
	exit(0);
}
