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
		ii menor;
		vector<ii> arr(n);
		for(int i = 0; i < n; i++) cin >> arr[i].f;
		int aux;
		bool n0 = false, n1 = false;
		for(int i = 0; i < n; i++){
			cin >> aux;
			if(aux == 1) n1 = true;
			else n0 = true;
		}
		
		if(n0 and n1){
			cout << "Yes" << endl;
			continue;
		}
		
		bool flag = true;

		for(int i = 0; i < n-1; i++){
			if(arr[i].f > arr[i+1].f){
				flag = false;
				break;
			}
		}
	 
		if(flag) cout << "Yes" << endl;
		else cout << "No" << endl;
 
	}

	exit(0);
}
