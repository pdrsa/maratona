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
	int n; cin >> n;
	vector<int> b(n);
	for(int i = 0; i < n; i++) cin >> b[i];
	sort(b.begin(), b.end());

	int ans = 1;
	if(b[0] != 1) b[0]--;
	int lb = b[0];
	for(int i = 1; i < n; i++){
		if (b[i] != lb){
			if(b[i] > lb){
				ans++;
				if(b[i] > lb + 1) b[i]--;
				lb = b[i];
			}
		}
		else{
			b[i]++;
			lb = b[i];
			ans++;
		}
	}
	cout << ans << endl;
	exit(0);
}
