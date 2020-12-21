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
	int n; cin >> n;
	vector<int> p;

	for(int i = 2; i <= n; i++){
		bool pr = true;
		for(auto u:p){
			if(i % u == 0){
				pr = false;
				break;
			}
		}

		if(pr){
			p.pb(i);
			cout << i << " ";
		}
	}
	cout << endl;
	exit(0);
}
