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
typedef pair<ll,ll> iill;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
int main(){ _
	int tt; cin >> tt;
	while(tt--){
		int n, m; cin >> n >> m;
		
		for(int j = 0; j < m; j++){
			if(j % 2 == 0) cout << 1;
			else cout << 0;
		}
		cout << endl;

		for(int i = 1; i < n-2; i++){
			cout << (i % 2 == 0) ? 0 : 1;
			for(int j = 1; j < m-1; j++)
				cout << 0;
			cout << (i % 2 == 0) ? 0 : 1;
			cout << endl;
		}

		for(int j = 0; j < m; j++) cout << 0;
		cout << endl;
		
		for(int j = 0; j < m; j++){
			if(j % 2 == 0) cout << 1;
			else cout << 0;
		}
		
		cout << endl << endl;
	}
	exit(0);
}
