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

vector<int> p(2020);

int find(int x){
	return p[x] = (x == p[x] ? x : find(p[x]));
}

bool uni(int x, int y){
	x = find(x), y = find(y);
	p[x] = y;
	return x != y;
}

int main(){ _
	for(int i = 0; i < 2020; i++) p[i] = i;
	int n; cin >> n;
	vector<bool> c(2020);
	set<int> ans;
	while(n--){
		int a, b; cin >> a >> b;
		b += 1000;
		uni(a,b);
		c[a] = true; c[b] = true;
	}
	for(int i = 0; i < 2020; i++){
		if(c[i]) ans.insert(find(i));
	}
	cout << ans.size() - 1 << endl;
	exit(0);
}
