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
	int x0, y0, x1, y1; cin >> x0 >> y0 >> x1 >> y1;
	cout << abs(x0 - x1) + abs(y0 - y1) << endl;
	exit(0);
}
