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
	vector<int> f(1e6 + 10);
	int n, m; cin >> n >> m;
	vector<int> ans(m + 10);
	vector<int> print(n);

	for(int i = 0; i < n; i++){
		cin >> print[i];
		if(print[i] <= m) f[print[i]]++;
	}
	
	for(int i = 1; i <= m; i++){
		for(int j = i; j <= m; j += i){
			ans[j] += f[i];
		}
	}

	int k = -INF, l;
	for(int i = 0; i <= m; i++){
		if(ans[i] > k) k = ans[i], l = i;
	}
	
	if(k == 0) l = 1;
	cout << l << " " << k << endl;
	for(int i = 0; i < n; i++)
		if(print[i] <= l and l % print[i] == 0) cout << i+1 << " ";
	
	cout << endl;
	exit(0);
}
