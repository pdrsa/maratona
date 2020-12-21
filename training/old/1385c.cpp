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
const int MAX = 2*1e5 + 10;

vector<int> a(MAX);
int n;

bool poss(int m){
	vector<int> ans;
	ans.pb(0);
	int l = m, r = n;
	while(l < r){
		int z = min(a[l], a[r]);
		if(z == a[l]) l++;
		else r--;

		if(z < ans[ans.size() - 1]) return false;
		ans.pb(z);
	}

	return true;
}


int main(){ _
	int t; cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0; i < n; i++) cin >> a[i];
		int l = 0, r = n-1;
		while(l<r){
			int m = (l+r)/2;
			if(poss(m)) r = m;
			else l = m+1;
		}

		cout << l << endl;
	}
	
	exit(0);
}
