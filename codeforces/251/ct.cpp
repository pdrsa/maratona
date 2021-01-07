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
	int n, k, p; cin >> n >> k >> p;
	queue<int> pares, impares;
	while(n--){
		int i; cin >> i;

		if(i% 2 == 0) pares.push(i);
		else impares.push(i);
	}
	
	int imp = impares.size(), par = pares.size();
	int rimp = (imp - (k-p));
	
	if(imp % 2 != (k-p) % 2 or rimp < 0 or p > (p + (rimp/2))){
		cout << "NO" << endl;
		exit(0);
	}
	
	cout << "YES" << endl;

	// Print pares
	for(int i = (p == k ? 1 : 0); i < p; i++){

		if(!pares.empty()){
			cout << 1 << " ";
			cout << pares.front() << endl;
			pares.pop();
		}

		else{
			cout << 2 << " ";
			cout << impares.front() << " ";
			impares.pop();
			cout << impares.front() << " " << endl;
			impares.pop();
		}

	}
	
	//Print impares
	for(int i = (p != k ? 1 : 0); i < (k-p); i++){
		cout << 1 << " " << impares.front() << endl;
		impares.pop();
	}
	
	//Print resto
	vector<int> ans;
	while(!pares.empty()){
		ans.pb(pares.front()); pares.pop();
	}
	while(!impares.empty()){
		ans.pb(impares.front()); impares.pop();
	}
	
	cout << ans.size() << " ";
	for(int i: ans) cout << i << " ";
	cout << endl;

	exit(0);
}
