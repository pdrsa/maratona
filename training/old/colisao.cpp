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
	int r1x0, r1y0, r1x1, r1y1; cin >> r1x0 >> r1y0 >> r1x1 >> r1y1;
	int r2x0, r2y0, r2x1, r2y1; cin >> r2x0 >> r2y0 >> r2x1 >> r2y1;
	
	if(max(r1x0, r2x0) <= min(r1x1, r2x1)){
		if(max(r1y0, r2y0) <= min(r1y1, r2y1)) cout << 1 << endl;
		else cout << 0 << endl;
	}
	else cout << 0 << endl;

	exit(0);
}
