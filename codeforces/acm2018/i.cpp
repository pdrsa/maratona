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
	int tt; cin >> tt;
	while(tt--){
		int x, n; cin >> x >> n;
		if(n > x){
			cout << -1 << endl;
			continue;
		}
		int chao = (x/n);
		int teto = (x+n-1)/n;
		for(int i = 0; i < n - (x%n); i++) cout << chao << " ";
		for(int i = 0; i < (x%n); i++) cout << teto << " ";
		cout << endl;
	}
	exit(0);
}
