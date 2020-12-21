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
	vector<int> h(n);
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> h[i];
	for(int i = 0; i < n; i++) cin >> v[i];

	if (h[0] > v[0]){
		cout << 0 << endl;
		exit(0);
	}

	int ans = v[0] - h[0];

	for(int i = 1; i < n; i++){
		if(v[i] - h[i] < ans) break;
		if(v[i] - h[i] > ans){
			ans++;
			break;
		}
	}

	cout << ans << endl;

	exit(0);
}
