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
	int n; cin >> n;
	vector<int> p;
	
	for(int i = 2; i <= n; i++){
		bool pr = true;
		for(int j = 2; j < i; j++)
			if(i % j == 0) pr = false;
		if(pr) p.pb(i);
	}

	vector<int> ans;
	for(int pr:p){
		int aux = pr;
		while(aux <= n){
			ans.pb(aux);
			aux *= pr;
		}
	}

	cout << ans.size() << endl;
	for(auto u: ans) cout << u << " ";
	cout << endl;
	
	exit(0);
}
