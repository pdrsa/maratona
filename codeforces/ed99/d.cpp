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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
	int tt; cin >> tt;
	while(tt--){
		int n, x; cin >> n >> x;
		vector<int> a(n); for(int &i:a) cin >> i;
		
		bool ok = true;
		for(int i = 1; i < n; i++){
			if(a[i] < a[i-1]) ok = false;
		}

		if(ok){
			cout << 0 << endl;
			continue;
		}
		
		int ans = 0;
		for(int i = 0; i < n; i++){
			
			bool check = true;
			for(int i = 1; i < n; i++){
				if(a[i] < a[i-1]) check = false;
			}

			if(check) break;
			

			if(x >= a[i]) continue;

			bool ok1 = true, ok2 = true;
			
			if(i != 0){
				if(a[i-1] > x) ok1 = false;
			}

			if(i != (n-1)){
				if(a[i+1] < x) ok2 = false;
			}
			
			if(i == (n-1) and a[i] >= a[i-1]) break;

			if(ok1 and ok2){
				ans++;
				swap(a[i], x);
			}
		}
		
		ok = true;
		for(int i = 1; i < n; i++) if(a[i] < a[i-1]) ok = false;

		cout << (ok ? ans : -1) << endl;

	}
	exit(0);
}
