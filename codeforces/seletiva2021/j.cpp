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
	int n; cin >> n;
	vector<int> b(n); for(int &i: b) cin >> i;
	sort(b.begin(), b.end());
	for(int i = 1; i <= n; i++){
		bool ok = true;
		for(int j = 0; j < n; j++){
			if(b[j] < (j/i)){
				ok = false;
				break;
			}
		}
		if(ok){
			cout << i << endl;
			break;
		}
	}

	exit(0);
}
