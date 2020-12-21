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
	int x11, x12, y11, y12, x21, x22, y21, y22;
	cin >> x11 >> x12 >> y11 >> y12;
	cin >> x21 >> x22 >> y21 >> y22;
	int x3 = max(min(x12, x22) - max(x11, x21), 0);
	int y3 = max(min(y12, y22) - max(y11, y21), 0);

	int a1 = (x12 - x11) * (y12 - y11);
	int a2 = (x22 - x21) * (y22 - y21);
	int a3 = y3 * x3;
	
	//cout << a1 << " " << a2 << " " << a3;
	cout << a1 + a2 - a3 << endl;
	exit(0);
}
