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
	int n;
	cin >> n;
	for (int a = 0; a < n; a++){
		ll q;
		cin >> q;
		if (q % 4 != 0){
			cout << "NO" << endl;
			continue;
		}
		ll soma = 0;
		cout << "YES" << endl;
		for (ll i = 2; i <= q; i+=2){
			soma += i;
			cout << i << " ";
		}

		for (ll i = 0; i < q/2; i++){
			if (i == (q/2 - 1)){
				cout << soma;
			}
			else{
				soma = soma - (i*2 + 1);
				cout << i*2 + 1 << " ";
			}
		}
		cout << endl;
	}
	exit(0);
}
