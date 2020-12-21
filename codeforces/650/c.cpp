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
		int n, k; cin >> n >> k;
		bool a[n];
		string s; cin >> s;
		for(int i = 0; i < n; i++){
			if(s[i] == '1') a[i] = true;
			else a[i] = false;
		}

		int v = 0;
		int ans = 0;
		bool empt = true;
		
		for(int i = 0; i < n; i++){
			if(v > (2*k) or (empt and (v > k))){
				ans++;
				v = k;
				empt = false;
			}

			if(!a[i]){
				v++;
				//cout << "i = " << i << " v = " << v << endl;
				if(i == n-1)
					if(v > k) ans++;
			}

			if(a[i]){
				v = 0;
				empt = false;
			}
		}
	
	if(empt) ans = max(ans, 1);
	
	cout << ans << endl;
	
	}
	exit(0);
}
