//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

// #define int ll
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> iill;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int32_t main(){ _
	int tt; cin >> tt;
	while(tt--){
		int k; cin >> k;
		string n; cin >> n;
		vector<int> nums(10);

		for(char c: n) nums[(c - '0')]++;
		
		bool ans = false;
		for(int i = 1; i < 10; i++){
			if(i == 2 or i == 3 or i == 5 or i == 7) continue;
			if(nums[i] > 0){
				cout << 1 << endl;
				cout << i << endl;
				ans = true;
				break;
			}
		}

		if(ans) continue;
		for(int i = 2; i < 10; i++){
			if(nums[i] > 1){
				cout << 2 << endl;
				cout << i << i << endl;
				ans = true;
				break;
			}
		}

		if(ans) continue;
		
		int lim = n.size();
		for(int mask = 1; mask < (1 << lim); mask++){
			string print;
			for(int i = 0; i < lim; i++)
				if(mask & (1 << i)) print.pb(n[i]);
			
			int t = stoi(print);
			for(int i = 2; i*i <= t; i++){
				if(t % i == 0){
					cout << print.size() << endl;
					cout << t << endl;
					ans = true;
					break;
				}
			}
			if(ans) break;
		}
	}
	exit(0);
}
