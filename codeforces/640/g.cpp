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
	vector<vector<int>> permutations;
	permutations.pb({2,1,3});
	for (int a = 0; a < 1000; a++){
		vector<int> aux = permutations[a];
		for(int i = 0; i < aux.size() - 1; i++){
			int act = a+4;
			int c1, c2;
			c1 = abs(aux[i] - act);
			c2 = abs(aux[i+1] - act);
			if(c1 > 1 and c1 < 5 and c2 > 1 and c2 < 5){
				aux.insert(aux.begin() + i + 1, act);
				break;
			}
		}
		permutations.pb(aux);
	}
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		if (n <= 3){
			cout << -1 << endl;
			continue;
		}
		for (auto u : permutations[n-3]) cout << u << " ";
		cout << endl;
	}
	exit(0);
}
