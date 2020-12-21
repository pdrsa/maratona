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
vector<vector<double>> pd;
vector<double> p;
int n;

double solve(int i, int j){
	if(i <= 0) return 0;
	if(j > i)  return 0;
	if(pd[i][j] != -1) return pd[i][j];

	double a, b;
	a = p[i-1] * solve(i-1, j-1);
	b = double(1-p[i-1]) * solve(i-1, j);
	
	return pd[i][j] = (a+b);
}

int main(){ _
	cin >> n;
	p = vector<double>(n); for(double &i:p) cin >> i;
	pd = vector<vector<double>> (n+1, vector<double>(n+1, -1));
	
	double p1 = 1, p2 = 1;
	for(int i = 1; i <= n; i++){
		p1 *= p[i-1];
		p2 *= double(1 - p[i-1]);
		pd[i][i] = p1;
		pd[i][0] = p2;
	}	

	double ans = 0;
	for(int j = (n+1)/2; j <= n; j++){
		ans += solve(n,j);
	}
	cout << setprecision(10) << ans << endl;
	

	exit(0);
}
