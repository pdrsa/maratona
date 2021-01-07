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
	int n, d; cin >> n >> d;
	int total = 0;
	
	for(int i = 0; i < n; i++){
		int a; cin >> a;
		total += a;
	}
	
	total = total + ((n-1)*10);
	if(total > d) cout << -1 << endl;
	else{
		cout << ((n-1) * 2) + ((d - total) / 5) << endl;
	}
	exit(0);
}
