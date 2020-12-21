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
		int n; cin >> n;
		int  n1 = 0; bool aux = true;
		ll s;
		for(int i = 0; i < n; i++){
			cin >> s;
			if(s == 1 and aux) n1++;
			if(s > 1 and aux){
				n1++;
				aux = false;
			}
		}
		if(n1 % 2 == 1) cout << "First" << endl;
		else cout << "Second" << endl;
	}
	exit(0);
}
