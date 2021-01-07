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
	vector<int> v(n+1);
	for(int i = 1; i <= n; i++) cin >> v[i];

	
	// Find someone equal
	for(int i = 1; i <= n; i++){
		
		if(v[i] == i){
			cout << "YES" << endl;
			for(int j = 1; j <= n; j++){
				if(j == i) continue;

				cout << j << " " << i << endl;
			}
			exit(0);
		}
	}
	
	if(n % 2 == 1){
		cout << "NO" << endl;
		exit(0);
	}

	int cont = 0;
	// Find a pair pointing to each other
	for(int i = 1; i <= n; i++){

		if(v[v[i]] == i){
			int a = min(v[i],i), b = max(v[i],i);

			cout << "YES" << endl;
			cout << a << " " << b << endl;
			cont++;

			set<int> print;

			for(int j = 1; j <= n and cont < n-1; j++){

				if(j == a or j == b or print.count(j)) continue;
				
				cout << a << " " << j << endl;
				cont++;

				if(cont < n-1){
					cout << b << " " << v[j] << endl;	
					cont++;
					print.insert(v[j]);
				}
			}
			
			exit(0);
		}

	}

	// If not, there's no answer (?)
	cout << "NO" << endl;

	exit(0);
}
