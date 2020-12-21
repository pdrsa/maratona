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
		vector<int> g(n);
		for(int i = 0; i < n; i++) cin >> g[i];
		sort(g.rbegin(), g.rend());
		int cont = 0;
		int aux = n;
		for(int i = 0; i < n; i++){
			if(g[i] > aux){
				cont++;
				aux--;
			}
		}
		cout << n - cont + 1 << endl;
	}
	exit(0);
}
