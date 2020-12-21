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
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; i++)
			cin >> a[i];
		sort(a.begin(), a.end());
		int ev = 0;
		bool flag = false;
		if (a[0] % 2 == 0) ev++;
		
		for(int i = 1; i < n; i++){
			if (a[i] % 2 == 0) ev++;
			if(abs(a[i] - a[i-1]) == 1) flag = true;
		}
		
		if((ev % 2 == 0) or flag) cout << "YES" << endl;
		else cout << "NO" << endl;

	}
	exit(0);
}
