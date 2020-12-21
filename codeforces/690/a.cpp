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

int main(){ _
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		vector<int> a(n); for(int &i:a) cin >> i;
		int l = 0, r = n-1;
		while(l <= r){
			cout << a[l] << " ";
			l++;
			if(l <= r) cout << a[r] << " ";
			r--;
		}
		cout << endl;
	}
	exit(0);
}
