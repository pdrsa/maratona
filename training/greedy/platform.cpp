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
	int n, m, d; cin >> n >> m >> d;
	d--;
	vector<int> p(m);
	int tot = 0;
	for(int &i: p){
		cin >> i;
		tot += i;
	}
	if(d * (m+1) + tot < n) cout << "NO" << endl;
	else{
		cout << "YES" << endl;
		int idx = 0;
		while(tot + d < n){
			for(int i = 0; i < d; i++) cout << "0 ";
			for(int i = 0; i < p[idx]; i++) cout << idx+1 << " ";  
			tot -= p[idx];
			n   -= d + p[idx];
			idx++;
		}
		for(int i = 0; i < (n - tot); i++) cout << "0 ";
		for(;idx < m; idx++){
			for(int i = 0; i < p[idx]; i++) cout << idx+1 << " ";
		}
		cout << endl;
	}

	exit(0);
}
