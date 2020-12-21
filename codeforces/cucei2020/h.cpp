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
const ll MAX = 1e4 + 2;
const ll MOD = 1e9 + 7;

vector<vector<int>> sum;

void pre(){
	vector<vector<int>> c(2, vector<int>(MAX));

	for(int i = 0; i < MAX; i++){
		for(int j = 0; j <= i; j++){
			if(j == 0 or j == i){
				c[i%2][j] = 1;
				
				if(j == 0)
					sum[i][j] = 1;
				else
					sum[i][j] = (sum[i][j-1] + 1) % MOD;
			}

			else{
				
				ll aux = c[(i+1)%2][j];
				ll aux2 = c[(i+1)%2][j-1];
				c[i%2][j] = (aux + aux2) % MOD;
				
				aux = sum[i][j-1];
				aux2 = c[i%2][j];
				sum[i][j] = (aux + aux2)  % MOD;
			}
		}
	}
}

int main(){ _
	sum.resize(MAX, vector<int>(MAX));
	pre();
	int tt; cin >> tt;
	while(tt--){
		
		int n, a, b; cin >> n >> a >> b; a--;
		if(a > n){
			cout << 0 << endl;
			continue;
		}
		b = min(b,n);

		ll ans = sum[n][b] - sum[n][a];
		
		cout << (ans % MOD + MOD) % MOD << endl;
	}
 
	exit(0);
}
