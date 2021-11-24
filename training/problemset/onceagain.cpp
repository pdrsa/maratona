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

template<typename T> int lis(vector<T> &v){
	vector<T> ans;
	for (T t : v){
		// Para non-decreasing use upper_bound()
		auto it = upper_bound(ans.begin(), ans.end(), t);
		if (it == ans.end()) ans.push_back(t);
		else *it = t;
	}
	return int(ans.size());
}

int main(){ _
	int n, t; cin >> n >> t;
	int sz   = min(400, t);
	
	vector<int> oc(310);
	vector<int> ov(n); for(int &i: ov){
		cin >> i;
		oc[i]++;
	}

	int maxi  = *max_element(oc.begin(), oc.end());
	int maxiE = -1;
	for(int i = 0; i < oc.size() and maxiE == -1; i++) if(oc[i] == maxi) maxiE = i;

	int maxiP = -1;
	int maxT  = 0;
	for(int i = 0; i < ov.size(); i++)
		if(ov[i] == maxiE){
			maxT++;
			if(maxiP == -1) maxiP = i;
		}

	vector<int> v(n * sz);
	for(int i = 0; i < n; i++) v[i] = ov[i];
	for(int i = n; i < n * sz; i++) v[i] = v[i-n];
	int ans = 0;
	ans += lis(v);

	ans += maxT * (t - sz);
	
	/*
	if(t > sz){
		vector<int> v2;
		for(int i = maxiP; i < n; i++) v2.pb(ov[i]);
		ans += lis(v2);
	}
	*/
	
	cout << ans << endl;
	exit(0);
}
