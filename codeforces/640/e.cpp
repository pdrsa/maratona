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
		vector<int> arr(n+1);
		vector<int> arr2(n);
		int aux;
		arr[0] = 0;
		for (int i = 1; i < n+1; i++){
			cin >> aux;
			arr2[i-1] = aux; 
			arr[i] = arr[i-1] + aux;
		}

		if (n < 3){
			cout << 0 << endl;
			continue;
		}
		
		int ans, l = 0; int r = 2, cont = 0;

		for (int a = 0; a < n; a++){
			aux = arr2[a];
			//cout << "For "<<aux<<endl;
			l = 0; r = 2;
			while(r < n+1){
				ans = arr[r] - arr[l];
				//cout << ans << " ";
				if (ans > aux){
					l++;
					if (l > r-2) r++;
				}
				if (ans < aux) r++;
				if (ans == aux) break;
			}
			//cout << endl;
			if (ans == aux) cont++;
		}
		
		cout << cont << endl;
	}

	exit(0);
}
