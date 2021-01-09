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

vector<int> p(110);

int find(int x){
	return p[x] = (x == p[x] ? x : find(p[x]));
}

bool uni(int x, int y){
	x = find(x), y = find(y);
	p[x] = y;
	return x != y;
}

int main(){ _
	for(int i = 0; i < 110; i++) p[i] = i;
	
	int n, m; cin >> n >> m;
	
	int ans = 0;
	vector<bool> us(110);

	while(n--){
		int x; cin >> x;
		if(x == 0) ans++;
		else{
			int z; cin >> z; x--;
			us[z] = true;
			while(x--){
				int a; cin >> a;
				us[a] = true;
				uni(a, z);
			}
		}	
	}
	set<int> comp;

	for(int i = 0; i < 110; i++){
		if(us[i]) comp.insert(find(i));
	}

	cout << ans + comp.size() - (comp.size() != 0) << endl;
	exit(0);
}
