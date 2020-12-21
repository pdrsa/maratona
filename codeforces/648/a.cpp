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
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		int arr[n][m];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> arr[i][j];
			}
		}
		
		int r = 0, c = 0;
		bool flag = true;
		for(int i = 0; i < n; i++){
			flag = true;
			for(int j = 0; j < m; j++){
				if(arr[i][j] == 1){
					flag = false;
				}
			}
			if(flag) r++;
		}

		for(int i = 0; i < m; i++){
			flag = true;
			for(int j = 0; j < n; j++){
				if(arr[j][i] == 1){
					flag = false;
				}
			}
			if(flag) c++;
		}

		if(min(r,c) % 2 == 0) cout << "Vivek" << endl;
		else cout << "Ashish" << endl;

	}
	exit(0);
}
