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

int main(){ _
	int n; cin >> n;
	vector<ll> b(n); for(ll &i: b){
		cin >> i;
		while(i % 2 == 0) i /= 2;
		while(i % 3 == 0) i /= 3;
	}
	bool ok = true;
	for(int i = 0; i < n-1; i++) if(b[i] != b[i+1]) ok = false;

	cout << (ok ? "YES" : "NO") << endl;
	exit(0);
}
