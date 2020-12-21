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
	vector<int> fib;
	int a = 1, b = 1, aux;
	fib.pb(1);
	while(a < 1000000){
		fib.pb(b);
		aux = b;
		b = a + b;
		a = aux;
	}
	vector<int> fibB(fib.size(), -1);
	int n; cin >> n;
	int found1 = -1;
	for(int i = 0; i < n; i++){
		cin >> aux;
		if(aux == 1){
			if(found1 != -1){
				cout << found1 << " " << i+1 << endl;
				exit(0);
			}
			else found1 = i+1;
		}
		if(binary_search(fib.begin(), fib.end(), aux)){
			int ix = lower_bound(fib.begin(), fib.end(), aux) - fib.begin();
			fibB[ix] = i+1;
		}
	}
	bool imp = true;
	for(int i = 0; i < fibB.size() - 1; i++){
		if(fibB[i] != -1 and fibB[i+1] != -1){
			cout << fibB[i] << " " << fibB[i+1] << endl;
			imp = false;
			break;
		}
	}

	if(imp) cout << "impossible" << endl;
	exit(0);
}
