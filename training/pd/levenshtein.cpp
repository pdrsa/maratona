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

int n;
vector<vector<int>> dp;

int main(){ _
	int tt; cin >> tt;
	while(tt--){
		string a, b; cin >> a >> b;
		int lena = a.size(), lenb = b.size();
		dp = vector<vector<int>> (lena+1, vector<int>(lenb+1));
		
		for(int i = 0; i <= lena; i++) dp[i][0] = i;
		for(int i = 0; i <= lenb; i++) dp[0][i] = i;

		for(int i = 1; i <= lena; i++){
			for(int j = 1; j <= lenb; j++){
				dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1,
				dp[i-1][j-1] + ((a[i-1] == b[j-1]) ? 0 : 1)});
			}
		}
		cout << dp[a.size()][b.size()] << endl;
	}
	exit(0);
}
