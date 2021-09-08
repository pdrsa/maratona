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

map<int, int> dp;

int main(){ _
	int n; cin >> n;
	vector<int> v(n); for(int &i: v) cin >> i;
	
	int ans = 0, ansVal;
	for(int x: v){
		if(dp.count(x - 1)) dp[x] = dp[x-1]+1;
		else dp[x] = 1;
		
		if(dp[x] > ans) ans = dp[x], ansVal = x;
	}
	cout << ans << endl;
	
	// Recuperando a sequência
	ansVal = ansVal - ans + 1; // Onde a sequência começa

	for(int i = 0; i < n; i++){
		if(v[i] == ansVal){
			cout << i+1 << " ";
			ansVal++;
		}
	}
	cout << endl;

	exit(0);
}
