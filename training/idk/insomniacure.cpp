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
	vector<int> a(4); int d;
	cin >> a[0] >> a[1] >> a[2] >> a[3] >> d;
	vector<bool> dra(d+1);
	for(auto z:a){
		for(int i = z; i <= d; i+=z) dra[i] = true;
	}
	int ans = 0;
	for(auto x:dra) if(x) ans++;
	cout << ans << endl;
	exit(0);
}
