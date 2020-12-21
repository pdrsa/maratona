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
		int n; cin >> n;
		vector<int> w(n);
		for(int i = 0; i < n; i++) cin >> w[i];
		sort(w.begin(), w.end());
		
		bool us[n];

		int ansA = 0, ans = 0;
		int test;

		for(int k = 2; k <= 100; k++){
			ansA = 0;
			memset(us, 0, sizeof us);
			for(int i = 0; i < n; i++){
				if(us[i]) continue;
				for(int j = i+1; j < n; j++){
					if(w[i] + w[j] == k and !us[j]){
						ansA++;
						us[j] = true;
						break;
					}
				}
			}
			if(ansA > ans) test = k;
			ans = max(ans, ansA);
		}
	
		cout << ans << endl;
	}
	exit(0);
}
