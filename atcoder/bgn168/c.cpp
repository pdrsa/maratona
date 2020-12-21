#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
#define PI 3.141592653589793

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
	long double a, b, h, m; cin >> a >> b >> h >> m;
	long double ang;
	ang = 2 * PI * (h/12 + m/60/12 - m/60);
	long double ans;
	ans = sqrt(a * a + b * b - (2*b*a*cos(ang)));
	printf("%.15Lf \n", ans);

	exit(0);
}
