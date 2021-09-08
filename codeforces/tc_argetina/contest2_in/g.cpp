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


int tri(int a, int b, int c){
	vector<int> v;
	v.pb(a), v.pb(b), v.pb(c);
	sort(v.begin(), v.end());
	//if(v[0] == v[1] and v[1] == v[2]) return 1;
	if(v[0] + v[1] == v[2]) return 1;
	if(v[0] + v[1] > v[2]) return 2;

	return 0;
}

int main(){ _
	int ans = 0;
	vector<int> t(4); for(int &i: t) cin >> i;
	for(int i = 0; i < 4; i++)
		for(int j = i+1; j < 4; j++)
			for(int k = j+1; k < 4; k++)
				ans = max(ans, tri(t[i], t[j], t[k]));

	if(ans == 0) cout << "IMPOSSIBLE" << endl;
	if(ans == 1) cout << "SEGMENT" << endl;
	if(ans == 2) cout << "TRIANGLE" << endl;
	exit(0);
}
