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
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		if(n == 3){
			cout << 3 << " " << 2 << " " << 1 << endl;
			cout << 1 << " " << 3 << " " << 2 << endl;
			cout << 3 << " " << 1 << " " << 2 << endl;
		} else{
			vector<int> perm(n);
			for(int i = 1; i <= n; i++) perm[i-1] = i;
			reverse(perm.begin(), perm.end());
			for(int j: perm) cout << j << " ";
			cout << endl;
			for(int i = 0; i < n-1;  i++){
				vector<int> per = perm;
				swap(per[i], per[i+1]);
				for(int j: per) cout << j << " ";
				cout << endl;
			}

		}
	}
	exit(0);
}
