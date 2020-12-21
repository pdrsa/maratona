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
	int n, m, k; cin >> n >> m >> k;
	vector<vector<bool>> s(n, vector<bool>(m));
	int sum = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char aux; cin >> aux;
			if(aux == '.'){
				s[i][j] = true; sum++;
			}
		}
	}

	if(k == 1){
		cout << sum << endl; exit(0);
	}
	
	ll cr = 0, cc = 0, ans = 0;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			// row
			if(s[i][j]) cr++;
			else{
				ans += max(0LL, (cr - k + 1)); cr = 0;
			}
		}
		ans += max(0LL, (cr - k + 1)); cr = 0;
	}

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			// column
			if(s[j][i]) cc++;
			else{
				ans += max(0LL, (cc - k + 1)); cc = 0;
			}
		}
		ans += max(0LL, (cc - k + 1)); cc = 0;
	}

	cout << ans << endl;
	exit(0);
}
