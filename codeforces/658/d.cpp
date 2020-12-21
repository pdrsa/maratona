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
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		vector<int> v(2*n);
		for(int i = 0; i < 2 * n; i++){
			cin >> v[i];
		}
		
		int ansAt = 0, ansF = 0;
		for(int i = 0; i < 2 * n; i++){
			ansAt = 0;
			for(int j = i; j < 2 * n; j++){
				if(v[j] < v[i]) ansAt++;
			}
			ansF = max(ansAt, ansF);
		}
		
		if(ansF >= n) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	exit(0);
}
