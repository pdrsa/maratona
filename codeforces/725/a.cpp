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
		int n; cin >> n;
		int minst = INF, maxst = -INF, mini, maxi;
		for(int i = 0; i < n; i++){
			int s; cin >> s;
			if(s < minst){
				minst = s;
				mini = i;
			}
			if(s > maxst){
				maxst = s;
				maxi = i;
			}
		}
		
		int a1 = max(mini, maxi) + 1;
		int a2 = min(maxi, mini) + 1 + (n - max(maxi, mini));
		int a3 = n - min(maxi, mini);

		cout << min({a1, a2, a3}) << endl;
	}
	exit(0);
}
