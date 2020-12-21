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
		int n, k; cin >> n >> k;
		set<int> s;
		int aux;
		for (int i = 0; i < n; i++){
			cin >> aux;
			s.insert(aux);
		}

		if (s.size() > k){
			cout << "-1" << endl;
			continue;
		}

		cout << k*n << endl;
		
		for (int i = 0; i < n; i++){
			auto it = s.begin();
			auto itend = s.end();
			itend--;
			
			for (int j = 0; j < k; j++){
				cout << *it << " ";
				if (it != itend)it++;
			}

		}

		cout << endl;


		
	}
	exit(0);
}
