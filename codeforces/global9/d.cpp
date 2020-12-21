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
		vector<int> arr(n);
		vector<int> is(1000, 0);
		for(int i = 0; i < n; i++){
			cin >> arr[i];
			is[arr[i]]++;
		}
		
		bool ans = false;
		vector<int> pos;
		int num;
		while(1){
			num = -1;
			ans = true;
			for(int i = 1; i < n; i++) if (arr[i] < arr[i-1]) ans = false;
			if(ans) break;
			for(int i = 0; i < n+1; i++){
				if(is[i] == 0){
					is[i]++;
					num = i;
					cout << "FOUND " << num << endl;
					break;
				}
			}
			bool find = false;
			int aux = max(0, min(num-1, n-1));
			is[arr[aux]]--;
			arr[aux] = num;
			pos.pb(aux);
		}
		cout << pos.size() << endl;
		for(auto u:pos) cout << u+1 << " ";
		cout << endl;

	}
	exit(0);
}
