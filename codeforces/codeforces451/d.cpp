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
	int n, m, k; cin >> n >> m >> k;
	vector<int> c(n); for(int &i:c) cin >> i;
	vector<bool> off(n);
	int l = 0, r = 0; 
	int act = 0; int ans = 0;
	
	sort(c.begin(), c.end());
	while(r < n){
		
		while(r < n and c[r] - c[l] < m){
			act++;
			
			if(act >= k){
				ans++;
				act--;
				off[r] = true;
			}

			r++;
		}

		while(r < n and (c[r] - c[l] >= m)){
			if(!off[l]) act--;
			l++; 
		}

	}

	cout << ans << endl;

	exit(0);
}
