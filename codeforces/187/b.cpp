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

int32_t main(){ _
	int n,m; cin >> n >> m;
	string a, b; cin >> a >> b;
	string aux = a;
	for(int i = 0; i < n-1 and i <= int(b.size() * 2); i++) a += aux;
	
	int j;
	int i;
	
	// First match
	for(i = 0, j = 0; i < int(a.size()) and j < int(b.size()); i++)
		if(a[i] == b[j]) j++;
	if(j < int(b.size())){
		cout << 0 << endl;
		exit(0);
	}

	// Second match
	ll pref  = i;
	ll found = 0;
	for(j = 0; i < int(a.size()); i++){
		if(a[i] == b[j]) j++;
		if(j == b.size()){
			found++;
			if(i < int(aux.size()) - 1)
				j = 0;
			else{
				i++;
				break;
			}
		}
	}

	ll val = i - pref;
	
	if(found == 0){
		if(m == 1) cout << 1 << endl;
		else cout << 0 << endl;
		exit(0);
	}
	
	ll restinho = 0;
	for(j = 0; i < int(a.size()); i++){
		if(a[i] == b[j]) j++;
		if(j == b.size()) j = 0, restinho++;
	}

	ll chars = (int(aux.size()) * n) - pref;
	ll count = 1 + (chars/val)*found + restinho;
	cout << "pref: " << pref << endl << "count: " << count << "restinho: " << restinho << endl;

	cout << count/m << endl;
	exit(0);
}
