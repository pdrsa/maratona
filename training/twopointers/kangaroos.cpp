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
	int n; cin >> n;
	vector<int>a(n); for(int &i: a) cin >> i;
	sort(a.begin(), a.end());
	cout << endl;
	int l = n-1, r = (n/2) - 1;
	int ans = 0;

	while(r >= 0){
		if(a[l] >= 2*a[r]){
			l--; r--; ans++;
		} else r--;
	}

	cout << n - ans << endl;
	exit(0);
}
