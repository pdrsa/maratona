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
	int n, l; cin >> n >> l;
	vector<double> lt(n);
	for(double &i: lt) cin >> i;
	sort(lt.begin(), lt.end());
	double maxi = lt[0];
	for(int i = 1; i < n; i++){
		maxi = max(maxi, (lt[i] - lt[i-1]) / 2);
	}
	maxi = max(maxi, (l - lt[n-1]));
	cout << setprecision(9) << maxi << endl;
	exit(0);
}
