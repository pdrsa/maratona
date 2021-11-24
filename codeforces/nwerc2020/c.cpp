//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
// #define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int32_t main(){ _
	double n, k, d, s; cin >> n >> k >> d >> s;
	double l = 0, r = 100;
	bool can = false;

	for(int i = 0; i < 2000; i++){
		double m = (l+r)/2;
		double median = s * k + m * (n-k);
		median /= n;
		if(abs(median - d) < 1e-12) can = true;

		if(median < d) l = m;
		else r = m;
	}

	cout << fixed << setprecision(8);
	if(can) cout << l << endl;
	else cout << "impossible" << endl;
	exit(0);
}
