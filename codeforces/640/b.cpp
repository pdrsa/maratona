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
		int n, k; cin >> n >> k;
		if (k > n){
			cout << "NO" << endl;
			continue;
		}

		if (n%2 == 0){
			if(k > n/2 and k%2 == 1){
				cout << "NO" << endl;
				continue;
			}
		}
		if (n%2 == 1){
			if (k%2 == 0){
				cout << "NO" << endl;
				continue;
			}
		}
		
		cout << "YES" << endl;
		if (k%2 == 0 or n%2 == 1){
			for (int i = 0; i < k - 1; i++){
				cout << "1 ";
			}
			cout << n-k+1 << endl;
		}
		else{
			for (int i = 0; i < k - 1; i++){
			cout << "2 ";
			}
			cout << n-(k*2)+2 << endl;
		}		
	}
	exit(0);
}
