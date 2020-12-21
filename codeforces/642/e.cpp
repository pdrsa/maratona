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
	int n, k; cin >> n >> k;
	bool l[n];
	vector<vector<int>> ans(n, {0, 0, -1});
	int aux;
	for (int i = 0; i < n; i++){
		cin >> aux;
		if (aux) l[i] = true;
		else l[i] = false;
	}

	for (int i = 1; i < n; i++){
		if (!l[i] and ans[i-1][2] != k-1)
			ans[i] = {ans[i-1][0], ans[i-1][1], -1};
		if (l[i] and ans[i-1][2] == k-1)
			ans[i] = {ans[i-1][0], ans[i-1][1]+1, (ans[i-1][2]+1)%k};
		if (l[i] and ans[i-1][2] != k-1){
			if (ans[i-1][1] <= ans[i-1][0] - 1)
				ans[i] = {ans[i-1][1], 0, -1};
			else
				ans[i] = {ans[i-1][0]+1, ans[i-1][1]+1, (ans[i-1][2]+1)%k};
		}
		if (!l[1] and ans[i-1][2] == k-1){
			if (ans[i-1][1] <= ans[i-1][0] - 1)
				ans[i] = {ans[i-1][1], 0, -1};
			else
				ans[i] = {ans[i-1][0]+1, ans[i-1][1], (ans[i-1][2]+1)%k};
		} 
	}

	cout << ans[n-1] << endl;
	}
	exit(0);
}
