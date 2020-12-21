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
	while (t--){
		int n; cin >> n;
		vector<int> ans(n);
		map<int, set<int>> mymap;
		mymap[n].insert(0);
		
		int cont = 1;
		while(mymap.rbegin() != mymap.rend()){
			auto it = mymap.rbegin();
			set<int> myset = it->s;
				int num  = it->f;
			if (num > n or num <= 0){
				mymap.erase(num);
				continue;
			}
			for (auto u: myset){
				if (num % 2 == 1){
					int pos = num/2;
					mymap[pos].insert(u);
					mymap[pos].insert(u+pos+1);
					ans[u+pos] = cont;
					cont++;
				}
				else{
					int pos1 = (num/2) - 1;
					int pos2 = (num/2);
					mymap[pos1].insert(u);
					mymap[pos2].insert(u + (num/2));
					ans[u+pos1] = cont;
					cont++;
				}
			}

			mymap.erase(num);
			if (cont > n) break;
		}

		for (auto u: ans) cout << u << " ";
		cout << endl;
		
	}
	exit(0);
}
