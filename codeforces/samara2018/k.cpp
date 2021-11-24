//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
// #define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<int> v;
int n, need;

bool solve(int m){
	int wasted = 0, got = 0;
	for(int i = 0; i < n; i++){
		if(v[i] <= got) got++;
		else if(wasted < m) wasted++, got++;
	}

	return got >= need;
}

int32_t main(){ _
	cin >> n >> need;
	v.resize(n); for(int &i:v) cin >> i;
	int l = 0, r = n+5;
	
	while(l < r){
		int mid = (l+r)/2;
		if(solve(mid)) r = mid;
		else l = mid+1;
	}

	cout << l << endl;
	exit(0);
}
