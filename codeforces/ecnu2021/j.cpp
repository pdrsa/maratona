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

double solve(double x){
	if(x > (1e7)) return log(x);
	else{
		double ans = 0;
		for(int i = 1; i <= x; i++) ans += (double(1)/double(i));
		return ans;
	}
}

int main(){ _
	double n, m, k; cin >> n >> m >> k;
	cout << fixed << setprecision(6) << endl;
	if(k < m) cout << (m-k) + (solve(n) - solve(m-1)) * m << endl;
	else cout << (solve(n) - solve(k-1)) * m << endl;
	exit(0);
}
