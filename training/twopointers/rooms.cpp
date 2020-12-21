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
	int n; cin >> n;
	vector<int> a(n); for(int &i:a) cin >> i;
	int l = 0, r = 0;
	vector<int> b(n+1);
	int ans = 0;
	vector<int> v(n);
	while(l < n){
		while(r < n){
			if(a[r] < 0) b[-a[r]]++;
			else if(b[a[r]] != 0) break;
			r++; ans++;
		}

		v[l] = ans;
		ans--;
		if(a[l] < 0) b[-a[l]]--;
		l++;
	}
	
	for(int i:v)cout << i << " ";
	cout << endl;
	
	exit(0);
}
