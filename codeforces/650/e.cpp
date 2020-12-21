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
		vector<int> b(26);
		char aux;
		int p;
		for(int i = 0; i < n; i++){
			cin >> aux;
			p = aux - 'a';
			b[p]++;
		}
		
		sort(b.rbegin(), b.rend());
		
		vector<int> div;
		int ans = 0;
		
		for(int i = 1; i <= n; i++){
			if(k % i == 0) div.pb(i);
		}
		
		int act;

		for(int i = 1; i <= n; i++){
		
			act = 0;
			for(int j = 0; j < 26; j++)
				act += b[j]/i;
			
			for(auto c:div)
				if(act >= c)
					ans = max(ans, c * i);
		}

		
		cout << ans << endl;
	}
	exit(0);
}
