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
	int n, q; cin >> n >> q;
	int aux;
	vector<int> a;
	for (int i = 0; i < n; i++){
		cin >> aux;
		a.pb(aux);
	}
	
	int as = n, pos = 0, menor = INF;
 
	for (int i = 0; i < q; i++){
		cin >> aux;
		if (aux > 0){
			
			if (i == q-1){
				cout << aux << endl;
				exit(0);
			}
			
			a.pb(aux);
			as++;
			if (aux < menor){
				menor = aux;
				if (pos > 0) pos--;
			}
		}
		else{
			if(abs(aux) == 1){
				pos++;
			}
			as--;
		}
	}
 
	sort(a.begin(), a.end());
	if (as <= 0) cout << 0 << endl;
	else cout << a[pos] << endl;
	exit(0);
}
