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
	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];
	int ans = 0;
	for(int num = 1; num <= 30; num++){
		int me  = 0;
		int met = 0;
		for(int i = 0; i < n; i++){
			if (arr[i] > num) me = 0;
			else me += arr[i];
			
			if (me < 0) me = 0;
			met = max(met, me);
		}
		ans = max(ans, (met-num));
	}

	cout << ans << endl;
	exit(0);
}
