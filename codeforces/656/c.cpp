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
		for(int i = 0; i < n; i++) cin >> arr[i];
		int ansAt = -1, ans = 0;
		bool cre = true;
		while(cre){
			ansAt = -1;
			for(int i = ans; i < n-1; i++){
				if(cre){
					if(arr[i] > arr[i+1]){
						cre = false;
						ansAt = i+1;
					}
				}
				
				else{
					if(arr[i] < arr[i+1]){
						cre = true;
						ans = ansAt;
						break;
					}
					else if(arr[i] > arr[i+1]) ansAt = i+1;
				}
			}

			if(ansAt == -1) break;
		}

		cout << ans << endl;
	}
	exit(0);
}
