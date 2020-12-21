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
		int n; cin >> n;
		bool m[n][n];
		string aux;
		for(int i = 0; i < n; i++){
			cin >> aux;
			for(int j = 0; j < n; j++){
				if(aux[j] == '1') m[i][j] = true;
				else m[i][j] = false;
			}
		}
		
		bool breaker = false;
		for(int i = 0; i < n-1; i++){
			for(int j = 0; j < n-1; j++){
				if(m[i][j]){
					if(!m[i+1][j] and !m[i][j+1]){
						breaker = true;
						break;
					}
				}
			}
			if(breaker) break;
		}

		if(breaker) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	exit(0);
}
