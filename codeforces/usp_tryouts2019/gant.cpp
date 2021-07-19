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

vector<ii> p;
vector<int> pw;

ii find(int x, int curP){
	curP = min(curP, p[x].f);
	if(p[x].s == x)
		return {curP, x};
	else 
		return p[x] = find(p[x].s, curP);
}

void uni(int x, int y){ p[y] = {pw[y], x}; }

int main(){ _
	int n, m; cin >> n >> m;
	pw = vector<int>(n);
	p  = vector<ii>(n);
	for(int &i: pw) cin >> i;
	for(int i = 0; i < n; i++) p[i] = {pw[i], i};
	
	while(m--){
		char c; cin >> c;
		if(c == '?'){
			int a; cin >> a; a--;
			cout << find(a, INF).f << endl;
		}
		else{
			int a, b; cin >> a >> b;
			a--, b--;
			uni(a,b);
		}
	}
	exit(0);
}

