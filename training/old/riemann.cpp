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
const ll MAX = 1300002;

int main(){ _
	vector<int> pr(MAX, -1);
	int n = 1;
	for(ll p = 2; p < MAX; p++){
		if(pr[p] == -1){
			for(ll i = p*p; i < MAX; i+=p){
				pr[i] = 0;
			}
			pr[p] = n;
			n++;
		}
	}

	int q; cin >> q;
	while(q--){
		int z; cin >> z;
		cout << pr[z] << endl;
	}

	exit(0);
}
