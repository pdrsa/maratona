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
		vector<ll> a(n+1); for (int i = 1; i <= n; i++) cin >> a[i];
		vector<ll> ans(n+1,1);
		for (int i = 1; i <=n; i++){
			for (int j = i+i; j <= n; j+= i){
				if(a[i] < a[j]){
					ans[j] = max(ans[j], ans[i]+1);
				}
			}
		}
		ll aux = 0;
		for (auto u:ans) aux = max(aux,u);
		cout << aux << endl;
	}
	exit(0);
}
